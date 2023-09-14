/*
    - There wil be three visiting schools
        - School A has six visiting groups (the default number)
        - School B has three visiting groups
        - School C has two visiting groups

    - For each visiting school, perform the following tasks
        - Randomize the animals
        - Assign the animals to the correct number of groups
        - Print the school name
        - Print the animal groups
*/

string[] pettingZoo =
{
    "alpacas", "capybaras", "chickens", "ducks", "emus", "geese",
    "goats", "iguanas", "kangaroos", "lemurs", "llamas", "macaws",
    "ostriches", "pigs", "ponies", "rabbits", "sheep", "tortoises",
};

PlanSchoolVisit("School A");
PlanSchoolVisit("School B", 3);
PlanSchoolVisit("School C", 2);

void PlanSchoolVisit(string schoolName, int groups = 6)
{
    RandomizeAnimals();
    string[,] group = AssignGroup(groups);
    Console.WriteLine(schoolName);
    PrintGroup(group);
}

void RandomizeAnimals()
{
    Random random = new Random();

    for (int i = 0; i < pettingZoo.Length; i++)
    {
        int r = random.Next(i, pettingZoo.Length);

        string temp = pettingZoo[i];
        pettingZoo[i] = pettingZoo[r];
        pettingZoo[r] = temp;
    }
}

string[,] AssignGroup(int groups = 6)
{
    string[,] result = new string[groups, pettingZoo.Length / groups];

    int start = 0;

    for (int i = 0; i < groups; i++)
        for (int j = 0; j < result.GetLength(1); j++)
            result[i, j] = pettingZoo[start++];

    return result;
}

void PrintGroup(string[,] groups)
{
    for (int i = 0; i < groups.GetLength(0); i++)
    {
        Console.Write($"Group {i + 1}: ");

        for (int j = 0; j < groups.GetLength(1); j++)
            Console.Write($"{groups[i, j]} ");

        Console.WriteLine();
    }
}
