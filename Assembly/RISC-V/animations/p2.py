from manim import *


class Title(Scene):
    def construct(self):
        Text.set_default(font="Open Sans")
        title = Text("Data Representation")
        self.play(Write(title))
        self.wait()
