Random random = new Random();

Console.WriteLine("Would you like to play? (Y/N)");

if (ShouldPlay()) PlayGame();

bool ShouldPlay()
{
    string input = Console.ReadLine();

    return input.ToLower().Equals("y");
}

void PlayGame()
{
    var play = true;

    while (play)
    {
        var target = GetTarget();
        var roll = RollDice();

        Console.WriteLine($"Roll a number greater than {target} to win!");
        Console.WriteLine($"You rolled a {roll}");
        Console.WriteLine(WinOrLose(roll, target));
        Console.WriteLine("\nPlay again? (Y/N)");

        play = ShouldPlay();
    }
}

int GetTarget()
{
    return random.Next(1, 6);
}

int RollDice()
{
    return random.Next(1, 7);
}

string WinOrLose(int roll, int target)
{
    return (roll > target) ? "You win!" : "You lose!";
}
