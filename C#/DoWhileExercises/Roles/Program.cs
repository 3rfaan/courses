string? input;
string role = "";

Console.WriteLine("Enter your role name (Administrator, Manager, or User)");

do
{
    input = Console.ReadLine();

    if (input != null)
    {
        role = input.Trim().ToLower();
    }

    if (role == "administrator" || role == "manager" || role == "user") break;
    else
    {
        Console.WriteLine($"The role name that you entered, \"{role}\" is not valid. Enter your role name (Administrator, Manager, or User)");

        role = "";
    }
} while (role == "");

Console.WriteLine($"Your input value ({role}) has been accepted.");


