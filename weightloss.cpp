#include <iostream> 
#include <iomanip> 
#include <string> 

using namespace std;

void bmrMale();
void bmrFemale();
double getIdealCal();

int actLevel, age;
string name, idealUnit;
char gender;
double idealWeight, weightKg, weightLb, cal, bmr;


int main()
{
    // Calculate users' basal metabolic rate (BMR) // 
    cout << setfill('-') << setw(55) << "" << endl;
    cout << "Welcome to your weight loss calculator.\nWe will start by asking you to tell us your gender.\n";
    cout << "We ask you for this because the calculation values vary depending your gender.\n";
    cout << "Please type M or m for male, and F or f for female: ";
    cin >> gender;
    cout << setfill('-') << setw(55) << "" << endl;


    if (gender == 'M' || gender == 'm')
    {
        bmrMale();
    }
    else if (gender == 'F' || gender == 'f')
    {
        bmrFemale();
    }
    else
    {
        cout << "Unrecognized gender :(. Please try again" << endl;
        exit(0);
    }


    // Calculate user's daily calories need according to their movement during work and their exercise style // 
    cout << "Now let's look at how many calories do you burn one day. Here is a list of activity level: \n";
    cout << "1. Sitting / lying all day \n";
    cout << "2. Seated work and no exercise \n";
    cout << "3. Seated work and light exercise \n";
    cout << "4. Moderate physical work and no exercise \n";
    cout << "5. Moderate physical work and light exercise \n";
    cout << "6. Moderate physical work and heavy exercise \n";
    cout << "7. Heavy physical work / heavy exercise \n";
    cout << "8. Above average physical work / exercise \n";
    cout << "Please type the number of your activity level: ";
    cin >> actLevel;

    if (actLevel == 1)
    {
        cal = bmr * 1.2;
        cout << endl;
    }
    else if (actLevel == 2)
    {
        cal = bmr * 1.3;
        cout << endl;
    }
    else if (actLevel == 3)
    {
        cal = bmr * 1.4;
        cout << endl;
    }
    else if (actLevel == 4)
    {
        cal = bmr * 1.5;
        cout << endl;
    }
    else if (actLevel == 5)
    {
        cal = bmr * 1.6;
        cout << endl;
    }
    else if (actLevel == 6)
    {
        cal = bmr * 1.7;
        cout << endl;
    }
    else if (actLevel == 7)
    {
        cal = bmr * 1.8;
        cout << endl;
    }
    else if (actLevel == 8)
    {
        cal = bmr * 2.2;
        cout << endl;
    }
    else
    {
        cout << "You entered an invalid number." << endl;
        exit(0);
    }
    cout << name << ", you burn " << cal << " calories a day! " << endl;
    cout << setfill('-') << setw(55) << "" << endl;


    // Suggest users how many calories they should consume each day to achieve their ideal weight // 
    double consumePerDay;
    cout << "It's time to see how many calories you should consume to lose weight and maintain a healthy body.\n";
    cout << "What's your ideal weight? Please type a number and its unit (lb or kg), separate them by space: ";
    cin >> idealWeight >> idealUnit;
    cout << setfill('-') << setw(55) << "" << endl;

    consumePerDay = getIdealCal();
    cout << "*To achieve your ideal weight, you should consume " << consumePerDay << " calories per day*. \n";

    //Suggest user how to divide their calories through macros 
    double protein;
    double carbohydrates;
    double fats;

    protein = consumePerDay * 0.5 / 4;
    carbohydrates = consumePerDay * 0.35 / 4;
    fats = consumePerDay * 0.15 / 9;

    cout << fixed << showpoint << setprecision(2);
    cout << "\nConsidering how many calories you need to consume to achive your ideal weight, you should consume: \n" << "1.-" << protein << " grams of protein. \n" << "2.-" << carbohydrates << " grams of carbohydrates. \n" << "3.-" << fats << " grams of fats. \n";
    cout << setfill('-') << setw(55) << "" << endl;
    cout << "Some suggestions:" << endl;
    cout << "\n-Protein intake: lean proteins(protein that is low in saturated fat)." << endl;
    cout << "some examples of lean proteins are: eggs, beef, salmon, turkey, chicken breast." << endl;
    cout << "-Carbohydrates intake: high fiber or complex carbohydrates. Some examples of high" << endl;
    cout << "fiber carbs are: quinoa, lentils, oats, kidney beans, whole wheat pasta, chickpea, wheat bran." << endl;
    cout << "-Fats intake: monounsaturated and polyunsaturated. Some examples: Olive, peanut, and canola oils," << endl;
    cout << "avocados, almonds, hazlenuts, peacans, pumpkin seedsand sesame seeds." << endl;
    cout << setfill('-') << setw(55) << "" << endl;

    //Weekly average of weight loss 
    double dailyCalDeficit;
    dailyCalDeficit = cal - consumePerDay;

    double weeklyCalDeficit;
    weeklyCalDeficit = dailyCalDeficit * 7;

    double weeklyWeightloss{};
    if (idealUnit == "lb" || idealUnit == "LB") 
    {
        weeklyWeightloss = weeklyCalDeficit / 3500;
        cout << "1.- With your calorie intake of " << consumePerDay << " you will be lossing an average of " << weeklyWeightloss << " lbs per week." << endl;
    }
    else if (idealUnit == "kg" || idealUnit == "KG") 
    {
        weeklyWeightloss = (weeklyCalDeficit / 3500) / 2.2;
        cout << "1.- With your calorie intake of " << consumePerDay << " you will be lossing an average of " << weeklyWeightloss << " kg per week." << endl;
    }
    else
    {
        cout << "Unrecognized unit. Please retry." << endl;
        exit(0);
    }

    //monthly average of weight loss 
    double monthlyWeightloss;
    if (idealUnit == "lb" || idealUnit == "LB")
    {
        monthlyWeightloss = weeklyWeightloss * 4;
        cout << "2.- Your monthly average weight loss : " << monthlyWeightloss << " lbs monthly." << endl;
    }
    else if (idealUnit == "kg" || idealUnit == "KG")
    {
        monthlyWeightloss = (weeklyWeightloss * 4.0) / 2.2;
        cout << "2.- Your monthly average weight loss: " << monthlyWeightloss << " kgs monthly." << endl;
    }
    else
    {
        cout << "Unrecognized unit. Please retry." << endl;
        exit(0);
    }

    cout << "\nYou are able to have cheat days!!!During your cheat day consume an additional 300 calories per day." << endl;
    cout << "Your macros, which consisting of protein, carbohydrates, and fats can be altered during this day, you won't have to follow the suggested given." << endl;
    cout << setfill('-') << setw(55) << "" << endl;

    return 0;
}

//Funtions:
// 
//Male Funtion
void bmrMale()
{
    string unit;
    string gnr = "Male";

    cout << "Hello!, you selected " << gnr << " bmr calculation, our mission is help you so let's start working" << endl;
    cout << "Please type your name: ";
    cin >> name;
    cout << setfill('-') << setw(55) << "" << endl;

    cout << "Hi, " << name << "! It's nice to have you here, ready for a change?\n";
    cout << "our principal mission is to help you, never forget that you are capable of everything!\n";
    cout << "we will work as you like, so for your convenience tell us if you want to use imperial or metric units.\n";
    cout << "Please type imperial or metric as you want: ";
    cin >> unit;
    cout << setfill('-') << setw(55) << "" << endl;

    if (unit == "metric" || unit == "Metric")
    {
        double convM, mtrs;
        string exercise;

        cout << "You selected metric units" << endl;
        cout << "1.- First enter your age: ";
        cin >> age;
        cout << "2.- Now enter your weight in kilograms: ";
        cin >> weightKg;
        cout << "3.- Convert your height from meters to centimeters: ";
        cin >> mtrs;
        convM = mtrs * 100;
        cout << "4.- Your height in centimeters is: " << convM << endl;
        bmr = (10 * weightKg) + (6.25 * convM) - (5 * age) + 5;
        cout << "Your BMR is: " << bmr << endl;
        cout << setfill('-') << setw(55) << "" << endl;
    }
    //Imperial
    else if (unit == "imperial" || unit == "Imperial")
    {

        double conv, foot;
        string exercise;

        cout << "You Selected imperial units" << endl;
        cout << "1.- First enter your age: ";
        cin >> age;
        cout << "2.- Please enter your weight in pound: ";
        cin >> weightLb;
        cout << "3.- Let's convert your height from foot to inches: ";
        cin >> foot;
        conv = foot * 12;
        cout << "4.- Your height in inches is: " << conv << endl;
        bmr = (10 * (weightLb / 2.2)) + (6.25 * (2.54 * conv)) - (5 * age) + 5;
        cout << "Your BMR is: " << bmr << endl;
        cout << setfill('-') << setw(55) << "" << endl;
    }
    else
    {
        cout << "Unrecognized unit. Please retry." << endl;
        exit(0);
    }

}


//Female Funtion
void bmrFemale()
{
    string unit;
    string gnr = "Female";

    cout << "Hello!, you selected " << gnr << " bmr calculation, we're here to help you lose weight and motivate yourself" << endl;
    cout << "Let's start, please type your name: ";
    cin >> name;
    cout << setfill('-') << setw(55) << "" << endl;

    cout << "Hi " << name << "! It's nice to meet you, ready for a change?\n";
    cout << "our principal mission is to help you, never forget that you are capable of everything!\n";
    cout << "we will work as you like, so for your convenience tell us if you want to use imperial or metric units.\n";
    cout << "So please type imperial or metric: ";
    cin >> unit;
    cout << setfill('-') << setw(55) << "" << endl;

    if (unit == "metric" || unit == "Metric")
    {
        double mtrs, convM;
        string exercise;

        cout << "You selected metric units" << endl;
        cout << "1.- First enter your age: ";
        cin >> age;
        cout << "2.- Please enter your weight in kilogram: ";
        cin >> weightKg;
        cout << "3.- Convert your height from meters to centimeters: ";
        cin >> mtrs;
        convM = mtrs * 100;
        cout << "4.- Your height in centimeters is: " << convM << endl;

        bmr = (10 * weightKg) + (6.25 * convM) - (5 * age) - 161;
        cout << "Your BMR is: " << bmr << endl;
        cout << setfill('-') << setw(55) << "" << endl;
    }
    //Imperial
    else if (unit == "imperial" || unit == "Imperial")
    {
        double conv, foot;
        string exercise;

        cout << "You selected imperial units" << endl;
        cout << "1.- First enter your age: ";
        cin >> age;
        cout << "2.- Please enter your weight in pound: ";
        cin >> weightLb;
        cout << "3.- Convert your height from foot to inches: ";
        cin >> foot;
        conv = foot * 12;
        cout << "4.- Your height in inches is: " << conv << endl;
        bmr = (10 * (weightLb / 2.2)) + (6.25 * (2.54 * conv)) - (5 * age) - 161;
        cout << "Your BMR is: " << bmr << endl;
        cout << setfill('-') << setw(55) << "" << endl;

    }
    else
    {
        cout << "Unrecognized unit. Please retry." << endl;
        exit(0);
    }
}


double getIdealCal()
{
    if (gender == 'M' || gender == 'm')
    {
        double consumeCalM = 0;

        if (idealUnit == "lb" || idealUnit == "LB")
            consumeCalM = idealWeight * 12;

        if (idealUnit == "kg" || idealUnit == "KG")
            consumeCalM = idealWeight * 2.2 * 12;

        return consumeCalM;
    }
    else if (gender == 'F' || gender == 'f')
    {
        double consumeCalF = 0;

        if (idealUnit == "lb" || idealUnit == "LB")
            consumeCalF = idealWeight * 11;

        if (idealUnit == "kg" || idealUnit == "KG")
            consumeCalF = idealWeight * 2.2 * 11;

        return consumeCalF;
    }
    else
        cout << "Unable to calculate. Please retry." << endl;
    exit(0);
}
// agregar cual es el objetivo de la persona, si bajar de peso o subir de peso. Dependiendo de eso las kilocalorias que deben de consumir
