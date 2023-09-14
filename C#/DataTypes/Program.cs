// Signed integers
Console.WriteLine("Signed integral types:");

Console.WriteLine($"sbyte   : {sbyte.MinValue} to {sbyte.MaxValue}");
Console.WriteLine($"short   : {short.MinValue} to {short.MaxValue}");
Console.WriteLine($"int     : {int.MinValue} to {int.MaxValue}");
Console.WriteLine($"long    : {long.MinValue} to {long.MaxValue}");

// Unsigned integers
Console.WriteLine("");
Console.WriteLine("Unsigned integral types:");

Console.WriteLine($"byte    : {byte.MinValue} to {byte.MaxValue}");
Console.WriteLine($"ushort  : {ushort.MinValue} to {ushort.MaxValue}");
Console.WriteLine($"uint    : {uint.MinValue} to {uint.MaxValue}");
Console.WriteLine($"ulong   : {ulong.MinValue} to {ulong.MaxValue}");

// Floats
Console.WriteLine("");
Console.WriteLine("Floating point types:");

Console.WriteLine($"float  : {float.MinValue} to {float.MaxValue} (with ~6-9 digits of precision)");
Console.WriteLine($"double : {double.MinValue} to {double.MaxValue} (with ~15-17 digits of precision)");
Console.WriteLine($"decimal: {decimal.MinValue} to {decimal.MaxValue} (with 28-29 digits of precision)");

// Head-allocated data types
int[] data = new int[3];
