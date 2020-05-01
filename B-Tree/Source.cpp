#include "BTree.h"

int main(int argc, char* argv[])
{
	cout << "Hello";

	//ArgumentManager am(argc, argv);
	//const string in = am.get("input");
	//const string out = am.get("output");
	//const string command = am.get("command");

	ifstream inputFile("input71.txt");
	ifstream commandFile("command71.txt");
	ofstream outputFile("output71.txt");

	string givenCommand = "";
	int givenDegree = 0;
	BTree myTree;

	if (inputFile.fail() || commandFile.fail())
		outputFile << "ERROR: File failed to open" << endl;
	else
	{
		cout << "csfsfaefarefarefa " << endl;

		while (!inputFile.eof())
		{
			getline(commandFile, givenCommand);
			if (givenCommand != "")
			{
				if (givenCommand[6] == '=')
				{
					string numberOfDegree = givenCommand.substr(7, givenCommand.length() - 7);
					int degree = stoi(numberOfDegree);
					myTree.setDegree(degree);
					string newItem = "";
					while (getline(inputFile, newItem))
					{
						if (newItem != "")
						{
							stringstream newString(newItem);
							int tem;
							while (newString >> tem)
							{
								myTree.insert(tem);
							}
						}
					}
				}
				else if (givenCommand == "Inorder Traversal")
				{
					cout << "goes her";
					myTree.printInOrderPrivate(myTree.root, outputFile);
					outputFile << endl;
				}
				else if (givenCommand[5] == ' ')
				{
					stringstream anotherLevel(givenCommand);
					int l;
					string temp;
					anotherLevel >> temp >> l;
					myTree.printNUmberOfLevels(outputFile, l);
				}
			}
			
		}
	}

	inputFile.close();
	commandFile.close();
	outputFile.close();
	return 0;
}