#include <iostream>
#include <stack>

using namespace std;

void moveDisk(stack<int> &start, stack<int> &dest)
{
    int disk = start.top();
    start.pop();
    dest.push(disk);
}

void printTower(stack<int> tower)
{
    while (!tower.empty())
    {
        int disk = tower.top();
        tower.pop();
        for (int i = 0; i < disk; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void playTowerOfHanoi(int numDisks)
{
    stack<int> tower1, tower2, tower3;
    for (int i = numDisks; i >= 1; i--)
    {
        tower1.push(i);
    }
    while (tower3.size() != numDisks)
    {
        printTower(tower1);
        printTower(tower2);
        printTower(tower3);
        cout << "Move disk from: ";
        int start, dest;
        cin >> start;
        cout << "Move disk to: ";
        cin >> dest;
        if (start == 1 && dest == 2)
        {
            moveDisk(tower1, tower2);
        }
        else if (start == 1 && dest == 3)
        {
            moveDisk(tower1, tower3);
        }
        else if (start == 2 && dest == 1)
        {
            moveDisk(tower2, tower1);
        }
        else if (start == 2 && dest == 3)
        {
            moveDisk(tower2, tower3);
        }
        else if (start == 3 && dest == 1)
        {
            moveDisk(tower3, tower1);
        }
        else if (start == 3 && dest == 2)
        {
            moveDisk(tower3, tower2);
        }
        else
        {
            cout << "Invalid move!" << endl;
        }
    }
    cout << "Congratulations, you solved the puzzle!" << endl;
}

int main()
{
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    playTowerOfHanoi(numDisks);
    return 0;
}
