// Shlok Patel
// 24th February 2023
/* Offers the user a choice of a BMI (Body Mass Index) calculation,
 * A blood pressure assessment or a c
 * Cardiac risk score assessment and
 * implements separate functions for each of these options. */


// Necessary Libraries
#include <stdio.h>

// Macro definitions
#define SIZE 5

// Function Prototypes
void BmiCalc();
void BpCalc();
int CardiacRiskAssessmentM();
int CardiacRiskAssessmentF();
int DiabeticInput();
int SmokerInput();
double CholesterolInput();
double SBPInput();
int AgeInput();

// Global Variable Declaration
int gender;
int age;
int smoker;
int diabetic;
double cholesterol;
double sbp;


int main()
{
    // Variable Declaration
    int choice;

    // Asks the user whether they want to calculate their BMI, Blood Pressure or Cardiac Risk Assessment
    // If invalid choices are made user is prompted to input again
    // if Cardiac Risk Assessment is chosen they are asked their gender to categorise the Risk Assessment scores
    while(1)
    {
        printf("Please choose one of the following options:\n");
        printf("Option 1 : BMI\n");
        printf("Option 2 : Blood Pressure\n");
        printf("Option 3 : Cardiac Risk Assessment\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            BmiCalc();
            break;
        }
        else if(choice == 2)
        {
            BpCalc();
            break;
        }
        else if(choice == 3)
        {
            printf("Are You Male or Female\n1 = Male\n2 = Female\nYour Input:");
            scanf("%d", &gender);

            if(gender == 1)
            {
                CardiacRiskAssessmentM();
            }
            if(gender == 2)
            {
                CardiacRiskAssessmentF();
            }
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void BmiCalc() // Calculates a persons bmi based on their height and weight
{
    // declaration of variables
    double w , h;
    double BMI;

    // Asks the user for their weight and if it is greater than the heaviest person of all time keeps on asking them until valid input
    while(1)
    {
        printf("Please Enter Your Weight in Kg:\n");
        printf("Your Input:");
        scanf("%lf", &w);

        if(w >= 635)
        {
            printf("Invalid Input Please Try Again:\n");
        }
        else
        {
            break;
        }
    }

    // Asks the user for their height and if it is taller than the tallest person of all time keeps on asking them until valid input
    while(1)
    {
        printf("Please Enter Your Height in Meters:\n");
        printf("Your Input:");
        scanf("%lf", &h);

        if(h >= 2.72)
        {
            printf("Invalid Input Please Try Again:\n");
        }
        else
        {
            break;
        }
    }

    BMI = w / (h*h); // Calculates the BMI

    printf("Your BMI is %.2lf", BMI); // Prints the BMI

    // Categorises the Person based on their BMI
    if(BMI < 18.5)
    {
        printf("\nYou are UnderWeight");
    }
    else if(BMI >= 18.5 && BMI < 25)
    {
        printf("\nYou are Normal Weight");
    }
    else if(BMI >= 25 && BMI < 30)
    {
        printf("\nYou are Overweight");
    }
    else
    {
        printf("\nYou are Obese\n");
    }

}

void BpCalc() // Calculates the persons blood pressure based on systolic and diastolic readings
{
   // declaration of variables
   float systolic[SIZE];
   float diastolic[SIZE];
   float AverageSys = 0 , AverageDia = 0;

   // Asks user for 5 systolic and 5 diastolic blood pressure readings
    for(int i = 0; i < SIZE; i++)
    {
        printf("Please Enter Your Systolic Blood Pressure:");
        printf("\nYour Choice :");
        scanf("%f", &systolic[i]);


       printf("Please Enter Your Diastolic Blood Pressure:");
       printf("\nYour Choice :");
       scanf("%f", &diastolic[i]);

    }

    // Calculates the average of the 5 systolic readings
    for (int i = 0; i < SIZE ; ++i)
    {
        AverageSys += systolic[i];
    }
    AverageSys /= 5;

    printf("The Average of the Systolic Blood Pressures is %f" , AverageSys); // Prints the average systolic readings

    // Calculates the average of the 5 diastolic readings
    for (int i = 0; i < SIZE ; ++i)
    {
        AverageDia += diastolic[i];
    }
    AverageDia /= 5;

    printf("\nThe Average of the Diastolic Blood Pressures is %f" , AverageDia); // Prints the average diastolic readings

    // Categorises the persons blood pressure based on their systolic and diastolic readings
    if(AverageSys <= 90 && AverageDia <= 60)
    {
        printf("\nYour Blood Pressure is Low");
    }
    else if((AverageSys <= 120 && AverageSys > 70) && (AverageDia <= 80 || AverageDia > 60))
    {
        printf("\nYour Blood Pressure is Ideal");
    }
    else if((AverageSys <= 140 && AverageSys > 70) && (AverageDia <=90 || AverageDia > 80))
    {
        printf("\nYour Blood Pressure is Pre-High");
    }
    else if((AverageSys <= 190 && AverageSys > 70) && (AverageDia <= 100 || AverageDia > 90))
    {
        printf("\nYour Blood Pressure is High");
    }
    else
    {
        printf("\nInvalid Inputs");
    }

}

int CardiacRiskAssessmentM() // Calculates the cardiac risk assessment of Male
{
    AgeInput(); // Asks the user for there age

    // Calculates all possible categories with age and gender input
    if(gender == 1  && age >= 80)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 1 && (age >= 30 && age <= 39))
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }

    SBPInput(); // Asks user for there sbp

    // Calculates all possible categories with sbp input and previous inputs
    if(gender == 1 && (age <= 49 && age >= 40) && sbp < 140)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }

    DiabeticInput(); // Asks users if they are diabetic

    // Calculates all possible categories with diabetic input and previous inputs
    if(gender == 1 && diabetic == 2 && (age <= 49 && age >= 40) && sbp < 160)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1  && (age <= 49 && age >= 40) && sbp >= 180)
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1 && (age <= 79 && age >= 70) && sbp >= 140)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 2 && (age <= 59 && age >= 50) && sbp < 140)
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1 && (age <= 59 && age >= 50) && (sbp <= 160 && sbp >= 140))
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1 && (age <= 79 && age >= 70) && sbp < 140)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1 && (age <= 69 && age >= 60) && (sbp < 160 && sbp >= 140))
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }

    SmokerInput(); // Asks users if they are diabetic

    // Calculates all possible categories with smoker input and previous inputs
    if(gender == 1 && smoker == 2 && (age <= 49 && age >= 40) && sbp < 160)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && (age <= 59 && age >= 50) && sbp < 140)
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && (age <= 79 && age >= 70) && sbp >= 140)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && (age <= 79 && age >= 70) && sbp < 140)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && (age <= 69 && age >= 60) && (sbp < 160 && sbp >= 140))
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && (age <= 59 && age >= 50) && (sbp < 160 && sbp >= 140))
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && diabetic == 2 && (age <= 79 && age >= 70) && sbp >= 140)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 2 && smoker == 2 && (age <= 59 && age >= 50) && (sbp < 160 && sbp >= 140))
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1))  && (age <= 59 && age >= 50) && sbp >= 160)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 1 && smoker == 1 && (age <= 59 && age >= 50) && sbp >= 160)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 2 && smoker == 2 && (age <= 59 && age >= 50) && (sbp > 160 && sbp < 180 ))
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if( gender == 1 && smoker == 2 && diabetic == 2 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && diabetic == 2 && (age <= 69 && age >= 60) && sbp >= 140)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 &&  ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)) && (age <= 69 && age >= 60) &&  sbp >= 160)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && (age <= 69 && age >= 60) && sbp >= 180)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && diabetic == 2 && (age <= 79 && age >= 70) && sbp < 140)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }

    CholesterolInput(); // Asks users for their cholesterol

    // Calculates all possible categories with cholesterol input and previous inputs
    if(gender == 1 && smoker == 1 && diabetic == 1 && (age <= 49 && age >= 40) && (sbp < 160 && sbp >= 140))
    {
        printf("Your Category : Mild 5%% to 9%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && cholesterol <= 6.4 && (age <= 49 && age >= 40) && sbp < 180)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && cholesterol >= 6.5 && (age <= 49 && age >= 40) && (sbp < 180 && sbp >= 160))
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && (age <= 49 && age >= 40) && (sbp < 180 && sbp >= 160))
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else  if(gender == 1 && diabetic == 2 && cholesterol <= 6.4 && (age <= 49 && age >= 40) && sbp < 180)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 2 && smoker == 2 && (age <= 49 && age >= 40))
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && diabetic == 2 && cholesterol <= 5.2 && smoker == 1 && (age <= 49 && age >= 40) && sbp >= 180)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && cholesterol >= 5.2 && (age <= 49 && age >= 40) && sbp >= 180)
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && (cholesterol < 5.2 || cholesterol >= 7.8) && (age <= 59 && age >= 50) && sbp < 140)
    {
        printf("Your Category : Mild < 5%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && (cholesterol <= 7.7 && cholesterol >= 5.2) && (age <= 59 && age >= 50) && sbp < 140)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 &&  cholesterol >= 5.2 && (age <= 59 && age >= 50) && sbp >= 180)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 2 && cholesterol >= 5.2 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 2 && cholesterol < 5.2 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && diabetic == 1 && cholesterol < 5.2 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 2 && diabetic == 1 && cholesterol >= 5.2 && (age <= 69 && age >= 60) && sbp < 140)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && cholesterol <= 6.4 && (age <= 69 && age >= 60) && (sbp <= 180 && sbp >= 160))
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 1 && smoker == 1 && diabetic == 1 && cholesterol >= 6.5 && (age <= 69 && age >= 60) && (sbp <= 180 && sbp >= 160))
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }

    return 0;
}
int CardiacRiskAssessmentF() // Calculates the cardiac risk assessment of Female
{
    AgeInput(); // Asks the user for there age

    // Calculates all possible categories with age and gender input
    if(gender == 2 && (age >= 30 && age <= 49))
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }
    else if(gender == 2 && age >= 80)
    {
        printf("Your Category : Low < 5%%\n");
        return 0;
    }

    SBPInput(); // Asks user for there sbp
    SmokerInput(); // Asks user if they smoke

    // Calculates all possible categories with sbi, smoke and previous inputs
    if(gender == 2 && smoker == 1  && (age <= 79 && age >= 70) && sbp >= 180)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 2 && (age <= 59 && age >= 50) && sbp < 180)
    {
        printf("Your Category : Mild 5%% to 9%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 1 && (age <= 59 && age >= 50) && sbp < 180)
    {
        printf("Your Category : Mild 5%% to 9%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 1 && (age <= 69 && age >= 60) && sbp >= 180)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }

    DiabeticInput(); // Asks user if they are diabetic

    // Calculates all other categories that also require diabetic
    if(gender == 2 && diabetic == 1 && (age <= 79 && age >= 70) && sbp >= 180)
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 2 && diabetic == 1 && smoker == 1 && (age <= 79 && age >= 70))
    {
        printf("Your Category : Very High ≥ 30%%\n");
        return 0;
    }
    else if(gender == 2 && ((diabetic == 1 && smoker == 2) || (diabetic == 2 && smoker == 1)) && (age <= 79 && age >= 70) && sbp < 180)
    {
       printf("Your Category : High 20%% to 29%%\n");
        return 0;
    }
    else if(gender == 2 && diabetic == 2 && smoker == 2  && (age <= 79 && age >= 70) && sbp < 180)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 2 && diabetic == 2 && smoker == 2 && (age <= 79 && age >= 70) && sbp >= 180)
    {
        printf("Your Category : High 20%% to 29%%\n");
        return 0;
    }
    else if(gender == 2 && diabetic == 1 && smoker == 1  && (age <= 59 && age >= 50) && sbp < 180)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 1 && diabetic == 1 && (age <= 59 && age >= 50) && sbp >= 180)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 2 && diabetic == 2 && (age <= 59 && age >= 50) && sbp >= 180)
    {
        printf("Your Category : Mild 5%% to 9%%\n");
        return 0;
    }
    else if(gender == 2 && ((smoker == 2 && diabetic == 1) || (smoker == 1 && diabetic == 2))  && (age <= 69 && age >= 60) && sbp < 180)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 1 && diabetic == 1 && (age <= 69 && age >= 60) && sbp < 180)
    {
        printf("Your Category : Moderate - High 15%% to 19%%\n");
        return 0;
    }
    else if( gender == 2 && smoker == 2 && diabetic == 2  && ( age <= 69 && age >= 60 ) && sbp < 180)
    {
        printf("Your Category : Mild 5%% to 9%%\n");
        return 0;
    }
    else if(gender == 2 && diabetic == 1 && (age <= 69 && age >= 60) && sbp >= 180)
    {
        printf("Your Category : High 15%% to 19%%\n");
        return 0;
    }
    else if(gender == 2 && smoker == 2 && diabetic == 2 && (age <= 69 && age >= 60) && sbp >= 180)
    {
        printf("Your Category : Moderate 10%% to 14%%\n");
        return 0;
    }

    return 0;
}

int DiabeticInput() // Asks the user whether they are diabetic or not
{
    while(1)
    {
        printf("Do You have Diabetes\n1 = Yes\n2 = No\nYour Option"); // Asks the user whether they are diabetic
        scanf("%d", &diabetic);

        while(diabetic == 1 || diabetic == 2) // if invalid input asks them until valid input
        {
            return diabetic; // returns the user input back
        }
    }
}

int SmokerInput() // Asks the user whether they smoke or not
{
    while(1)
    {
        printf("Do You Smoke\n1 = Yes\n2 = No\nYour Option"); // Asks the user if they smoke by giving them 2 options.
        scanf("%d", &smoker);

        while (smoker != 1 || smoker != 2)  // if incorrect input asks them again.
        {
            return smoker; // Returns the users input back.
        }
    }

}

double CholesterolInput() // Gets the cholesterol value from the user
{
    printf("What is your Cholesterol\n Your Input:"); // Asks for Your Cholesterol as Input
    scanf("%lf", &cholesterol);

    return cholesterol; // returns the inputed value
}

double SBPInput()  // Gets the systolic blood pressure value from the user
{
    printf("What is Your Systolic Blood Pressure\nYour Input:"); // Asks the user for systolic blood pressure
    scanf("%lf", &sbp);

    return sbp; // returns the systolic blood pressure value
}

int AgeInput() // Gets the age of the user
{
    printf("What is your age\n Your Input:"); // Asks the user for their age
    scanf("%d", &age);

    return age; // Returns the age of the user
}


