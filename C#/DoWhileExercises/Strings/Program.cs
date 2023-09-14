int periodLocation;

string newString;
string output;

string[] myStrings = new string[2] {
    "I like pizza. I like roast chicken. I like salad",
    "I like all three of the menu choices"
};

foreach (string myString in myStrings)
{
    newString = myString;
    periodLocation = newString.IndexOf(".");

    while (periodLocation != -1)
    {
        output = newString.Remove(periodLocation).Trim();
        newString = newString.Substring(periodLocation + 1);

        periodLocation = newString.IndexOf(".");

        Console.WriteLine(output);
    }
    output = newString.Trim();
    Console.WriteLine(output);
}
