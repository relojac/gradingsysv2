#include <iostream>
#include <cmath>
using namespace std;

/*
    i COULD optimize this code but it works so why bother
    also i have no idea what half of this does
    i may have lost the plot
    144 FUCKING LINES?????
*/

// weights for each component someone please change these defaults why has the reference code not been sent yet i have literally just been forced to write this completely blind someone help
double weights[] {
    0.3,
    0.5,
    0.2
};

const string us_main[] = {
    "your weighted score is: ",
    "type your ",
    " score: ",
    "your average grade is: ",
    "but it's been rounded to: ",
    "average scores :3 \n\n"
};
const string us_weight[] = {
    "enter ",
    " weight (0-1) \nenter 0 for default (",
    "): ",
    "\nwarning: weights do not add up to 1. \nyour grade may be inaccurate \n\n"
};
const string us_cat[] = {
    "written work",
    "performance task",
    "exam"
};
const string us_range[] = {
    " isn't a number within 0-100!! \n\n",
    "input again: "
};
const string us_eval[] = {
    "your average grade is lower than the passing score D: \n",
    "you have a passing score :) \n",
    "you would be a honor student :D \n",
    "with high honors ! :0 \n",
    "PERFECT :O \n"
};
const string us_egg[] = {
    "\nhi ! \n\n",
    "thanks for reading my spaghetti code \n",
    "please make sure to never use it \n\n",
    "byee :3 \n\n6969/69420\n"
};

void evalGrade(double g)
{
    if (g < 75) cout << us_eval[0];
    else if (g < 90) cout << us_eval[1];
    else if (g < 95) cout << us_eval[2];
    else if (g < 100) cout << us_eval[3];
    else if (g == 100) cout << us_eval[4];
}

double validate()
{
    double score;
    while (true)
    {
        cin >> score;

        if (cin.fail() || ((score != 6969 && score != 69420) && (score > 100 || score < 0)))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << score << us_range[0] << us_range[1];
            continue;
        }
        else if (score == 6969 || score == 69420)
        {
            for (int i = 0; i < 4; i++) cout << us_egg[i];
            exit(6969); // this is supposed to exit this is not an error
        }
        else return score;
    }
}

double score(double weight, int cat)
{
    double s;
    cout << us_main[1] << us_cat[cat] << us_main[2];
    s = validate();

    double sS = s*weight;
    cout << us_main[0] << sS << "\n\n";

    return sS;
}

double weightSelect(int p)
{
    double selected;
    cout << us_weight[0] << us_cat[p] << us_weight[1] << weights[p] << us_weight[2];
    cin >> selected;

    return (selected != 0) ? selected : weights[p];
}
void weightCheck(double w1, double w2, double w3)
{
    double sum = w1+w2+w3;
    if (abs(sum - 1.0) > 1e-6)
    {
        cout << us_weight[3];
    }
}

int main()
{
    // scores for each component after weight
    double scores[] {
        0,
        0,
        0
    };

    cout << us_main[5];

    for (int i1 = 0; i1 < 3; i1++)
    {
        weights[i1] = weightSelect(i1);
        cout << weights[i1] << "\n\n";
    }
    weightCheck(weights[0], weights[1], weights[2]);

    for (int i = 0; i < 3; i++) scores[i] = score(weights[i], i);

    double a = scores[0]+scores[1]+scores[2]; // sum of weighted scores
    int ra = round(a);
    cout << us_main[3] << a << "\n";
    cout << us_main[4] << ra << "\n\n";
    evalGrade(ra);

    return 0;
}