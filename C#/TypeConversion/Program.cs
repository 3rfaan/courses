/*
string[] values = { "12.3", "45", "ABC", "11", "DEF" };

float total = 0.0f;
string message = "";


foreach (string value in values)
{
    float parsedNumber = 0.0f;

    if (float.TryParse(value, out parsedNumber))
        total += parsedNumber;
    else
        message += value;
}

Console.WriteLine($"Message: {message}");
Console.WriteLine($"Total: {total}");
*/

int value1 = 12;
decimal value2 = 6.2m;
float value3 = 4.3f;

int result1 = Convert.ToInt32(value1 / value2);
Console.WriteLine($"Divide value1 by value2, display the result as an int: {result1}");

decimal result2 = value2 / (decimal)value3;
Console.WriteLine($"Divide value2 by value3, display the result as a decimal: {result2}");

float result3 = value3 / value1;
Console.WriteLine($"Divide value3 by value1, display the result as a float: {result3}");
