/*
string pangram = "The quick brown fox jumps over the lazy dog";

string[] words = pangram.Split(" "); // ["The", "quick", "brown", ..., "dog"]
string[] reversedWords = new string[words.Length];

for (int i = 0; i < words.Length; i++)
{
    char[] letters = words[i].ToCharArray();

    Array.Reverse(letters);
    reversedWords[i] = new string(letters);
}

string result = String.Join(" ", reversedWords);

Console.WriteLine(result);
*/

string orderStream = "B123,C234,A345,C15,B177,G3003,C235,B179";
string[] orders = orderStream.Split(',');

Array.Sort(orders);

foreach (string order in orders)
    if (order.Length == 4)
        Console.WriteLine(order);
    else
        Console.WriteLine($"{order}     - Error");
