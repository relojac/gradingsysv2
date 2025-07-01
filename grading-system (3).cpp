// WIRES //
#include <iostream> // literally everything
#include <cmath> // round() blah blah blah
#include <iomanip> // fixed and shit
using namespace std; // to simplify things

constexpr double defaultWeights[] =
{
    0.2,
    0.6,
    0.2
};

// CONFIG //
// you can change these values without worry :3
double weights[] = // default weights. make sure [0]+[1]+[2] = 1.00
{
    0.2, // written works
    0.6, // performance tasks
    0.2 // quarterly exams
};
constexpr bool VALIDATE_ENABLED = true;
constexpr bool WEIGHTINPUT_ENABLED = true;
constexpr int WEIGHTINPUT_FIX = 1; // 0 disable, 1 weight÷sum, 2 default weights
// const string LANGUAGE = "PH"; will make this when the challenge is over

// DIALOGUE SHIT //
/*
    make sure to use \n if you want multi line shit on the same text
    i will probably work on multi language support
*/
const string US_MAIN[] =
{
    "average grade calculator :0",
    "by relojac :3",

    "input your ", /* component */ " score: ", /* cin >> score */
    "your weighted score is ", /* weighted score */
    ":3 done ! your average grade is ", /* average */ ", but it was also rounded to ", /* rounded average */

    "(0 = default) input new ", /* component */ " weight: ",
    "the weights for each component don't add up to 1\nyour grade may be inaccurate",
    "the weights for each component don't add up to 1, so we've normalized it\nthis fix can be changed/disabled via WEIGHTINPUT_FIX in the config",
    "the weights for each component don't add up to 1, so we've reset it\nthis fix can be changed/disabled via WEIGHTINPUT_FIX in the config"
};
const string US_COMPONENT[] =
{
    "written works",
    "performance tasks",
    "quarterly exams"
};
const string US_RANGE[] =
{
    " is not a number within the 1-100 range",
    "input again: "
};

// don't edit anything below unless you know what you're doing
// FUNCTIONS //
double validate()
{
    double score;
    while (true)
    {
        cin >> score;

        if (cin.fail() || (score > 100 || score < 0))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << score << US_RANGE[0] << endl << endl << US_RANGE[1];

            continue;
        }
        else return score;
    }
}
double get_score(int phase)
{
    double score, weightedScore;

    cout << US_MAIN[2] << US_COMPONENT[phase] << US_MAIN[3];
    if (VALIDATE_ENABLED == true) score = validate();
    else cin >> score;
    weightedScore = score*weights[phase];

    cout << US_MAIN[4] << weightedScore << endl << endl;
    return weightedScore;
};
void weight_input(int phase)
{
    double newWeight;

    cout << US_MAIN[7] << US_COMPONENT[phase] << US_MAIN[8];
    cin >> newWeight;

    if (newWeight != 0) weights[phase] = newWeight;

    cout << weights[phase] << endl << endl;
};

// MAIN //
int main()
{
    cout << fixed << setprecision(1);

    double scores[] =
    {
        0,
        0,
        0
    };
    double a, rounded_a;

    if (WEIGHTINPUT_ENABLED == true)
    {
        for (int i = 0; i < 3; i++)
        {
            weight_input(i);
        }
        double sum = (weights[0]+weights[1]+weights[2]);

        if (sum-1 > 1e-6 || sum-1 < -1e-6)
        {
            if (WEIGHTINPUT_FIX == 0)
            {
                cout << US_MAIN[9] << endl << endl;
            }
            else if (WEIGHTINPUT_FIX == 1)
            {
                cout << US_MAIN[10] << endl << endl;
                for (int i = 0; i < 3; i++)
                {
                    weights[i] = weights[i]/sum;
                    cout << weights[i] << " - " << US_COMPONENT[i] << endl;
                }
                cout << endl;
            }
            else if (WEIGHTINPUT_FIX == 2)
            {
                cout << US_MAIN[11] << endl << endl;
                for (int i = 0; i < 3; i++) weights[i] = defaultWeights[i];
            }
        }
    }

    cout << US_MAIN[0] << endl << US_MAIN[1] << endl << endl;

    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_score(i);
    }

    a = scores[0]+scores[1]+scores[2];
    rounded_a = round(a);
    const double is_zero = a-rounded_a;

    if (is_zero > 1e-6 || is_zero < -1e-6)
    {
        cout << US_MAIN[5] << a;
        cout << setprecision(0) << US_MAIN[6] << rounded_a << endl;
    }
    else cout << setprecision(0) << US_MAIN[5] << a;

    return 0;
}
