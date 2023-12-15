#![allow(dead_code)]

use std::{
    marker::PhantomData,
    ops::Deref,
    ptr::NonNull,
    sync::atomic::{fence, AtomicUsize, Ordering},
};

pub struct Arc<T> {
    ptr: NonNull<ArcInner<T>>,
    phantom: PhantomData<ArcInner<T>>,
}

pub struct ArcInner<T> {
    rc: AtomicUsize,
    data: T,
}

unsafe impl<T: Sync + Send> Send for Arc<T> {}
unsafe impl<T: Sync + Send> Sync for Arc<T> {}

impl<T> Arc<T> {
    pub fn new(data: T) -> Arc<T> {
        let boxed = Box::new(ArcInner {
            rc: AtomicUsize::new(1),
            data,
        });

        Arc {
            ptr: NonNull::new(Box::into_raw(boxed)).unwrap(),
            phantom: PhantomData,
        }
    }
}

impl<T> Deref for Arc<T> {
    type Target = T;

    fn deref(&self) -> &T {
        let inner = unsafe { self.ptr.as_ref() };

        &inner.data
    }
}

impl<T> Clone for Arc<T> {
    fn clone(&self) -> Arc<T> {
        let inner = unsafe { self.ptr.as_ref() };
        let old_rc = inner.rc.fetch_add(1, Ordering::Relaxed);

        if old_rc >= isize::MAX as usize {
            std::process::abort();
        }

        Self {
            ptr: self.ptr,
            phantom: PhantomData,
        }
    }
}

impl<T> Drop for Arc<T> {
    fn drop(&mut self) {
        let inner = unsafe { self.ptr.as_ref() };

        if inner.rc.fetch_sub(1, Ordering::Release) != 1 {
            return;
        }

        fence(Ordering::Acquire);
        unsafe {
            let _ = Box::from_raw(self.ptr.as_ptr());
        }
    }
}
