string[,] corporate =
{
    {"Robert", "Bavin"}, {"Simon", "Bright"},
    {"Kim", "Sinclair"}, {"Aashrita", "Kamath"},
    {"Sarah", "Delucchi"}, {"Sinan", "Ali"}
};

string[,] external =
{
    {"Vinnie", "Ashton"}, {"Cody", "Dysart"},
    {"Shay", "Lawrence"}, {"Daren", "Valdes"}
};

string externalDomain = "hayworth.com";

for (int i = 0; i < corporate.GetLength(0); i++)
{
    DisplayMail(firstName: corporate[i, 0], lastName: corporate[i, 1]);
}


for (int i = 0; i < external.GetLength(0); i++)
{
    DisplayMail(firstName: external[i, 0], lastName: external[i, 1], domain: externalDomain);
}

void DisplayMail(string firstName, string lastName, string domain = "contoso.com")
{
    string mail = firstName.Substring(0, 2) + lastName;

    mail = mail.ToLower();
    Console.WriteLine($"{mail}@{domain}");
}
