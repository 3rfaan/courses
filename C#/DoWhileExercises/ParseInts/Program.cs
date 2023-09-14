string? input;
int num;
bool validNum;

Console.WriteLine("Enter an integer value between 5 and 10");

do
{
    input = Console.ReadLine();
    validNum = int.TryParse(input, out num);

    if (!validNum)
    {
        Console.WriteLine("Sorry, you entered an invalid number, please try again");
        continue;
    }
    else if (num < 5 || num > 10)
    {
        Console.WriteLine($"You entered {num}. Please enter a number between 5 and 10.");
        continue;
    }
    else break;
} while (input != null);

Console.WriteLine($"Your input value ({num}) has been accepted.");
