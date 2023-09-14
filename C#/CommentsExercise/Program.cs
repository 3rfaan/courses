/*
    This program converts a string to an array of chars, then reversing it.
    Also it counts how many times the letter `o` appears in the string, using
    the variable `x` as a counter. Then printing the results to the console.
*/

string originalMessage = "The quick brown fox jumps over the lazy dog.";

char[] message = originalMessage.ToCharArray();
Array.Reverse(message);

int count = 0;
foreach (char letter in message) { if (letter == 'o') { count++; } }

string reversedMessage = new String(message);

Console.WriteLine(reversedMessage);
Console.WriteLine($"'o' appears {count} times.");
