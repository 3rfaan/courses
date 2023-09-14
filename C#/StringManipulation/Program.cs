const string input = "<div><h2>Widgets &trade;</h2><span>5000</span></div>";

string quantity = "";
string output = "";

int length = 0;
int openingPosition = 0;
int closingPosition = 0;

// extracting quantity
const string openSpan = "<span>";
const string closeSpan = "</span>";

openingPosition = input.IndexOf(openSpan);
closingPosition = input.IndexOf(closeSpan);

openingPosition += openSpan.Length; // offset

length = closingPosition - openingPosition;

quantity += "Quantity: ";
quantity += input.Substring(openingPosition, length);

// processing output
const string tradeSymbol = "&trade;";
const string regSymbol = "&reg;";
const string openDiv = "<div>";
const string closeDiv = "</div>";

openingPosition = input.IndexOf(openDiv);
closingPosition = input.IndexOf(closeDiv);

openingPosition += openDiv.Length;

length = closingPosition - openingPosition;

output += "Output: ";
output += input.Substring(openingPosition, length);
output = output.Replace(tradeSymbol, regSymbol);

Console.WriteLine(quantity);
Console.WriteLine(output);
