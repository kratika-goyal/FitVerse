#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
char plan[7][5][200];
} WorkoutPlan;

void menu();

struct preference {
int diet;
int experience;
int workout;
};

struct profile {
char name[100];
int age;
char gender[20];
float height;
float weight;
float goal;
struct preference pref1;
};

struct profile p1;
void preference();
void profile();
void save_profile(struct profile p);
void load_profile(struct profile *p);
void edit_pref();
float BMI_cal(float height, float weight);
void BMI_category(float bmi);
void view_profile();
void vegan();
void vegetarian();
void nonvegetarian();
void diet();
void yoga();
void gym();
void homeWorkout();
void printPlanLevel();
void workout();
void printPlanLevel(WorkoutPlan planLevel);
void showYogaByLevel(int level);
void showGymByLevel(int level);
void showHomeByLevel(int level);
void home_repl();
void workout_menu();//
void trackDailyProgress();
void viewProgress();
void resetProgress();
void deleteprofile();
void edit_pref();
void clearScreen();
void pause();


int main() {

int choice;
int running = 1;
load_profile(&p1);
while (running) {
menu();
printf("Enter your choice\n");
scanf("%d", &choice);
clearScreen();

switch (choice) {
case 1:
profile();
break;
case 2:
edit_pref();
break;
case 3:
diet();
break;
case 4:
workout();
break;
case 5:
trackDailyProgress();
break;
case 6:
viewProgress();
break;
case 7:
view_profile();
break;
case 8:
deleteprofile();
break;
case 9:
printf("Exiting... Thank you!\n");
save_profile(p1);
running = 0;
break;
default:
printf("Invalid choice... Please choose again\n");
}

if (running) {
pause();
clearScreen();
}}
return 0;
}

void menu(){
 for(int i = 0; i < 30; i++){
    printf("~ ");
    }
printf("\n");
printf("            ");
for(int i = 0; i < 5; i++){
 printf("> ");
}
printf(" FitVerse ");
for(int i = 0; i < 5; i++){
    printf("< ");
}
printf("\n");
for(int i = 0; i < 30; i++){
    printf("~ ");
}
printf("\n\n");
printf("           Track it. Own it. Improve it.\n\n");

for(int i = 0; i < 59; i++){
    printf("=");
}
printf("\n\n");
printf("1. Make an account\n");
printf("2. Edit your prefernces\n");
printf("3. View your Diet plan\n");
printf("4. View your Workout plan\n");
printf("5. Track daily progress\n");
printf("6. View daily progress\n");
printf("7. View your profile\n");
printf("8. Delete your profile\n");
printf("9. Exit\n");
printf("\n");

for(int i = 0; i < 59; i++){
printf("=");
}
printf("\n\n");
}

void preference() {
    for(int i = 0; i < 59; i++){
    printf("=");
}
printf("\n");
    printf("                     ENTER YOUR PREFERENCES                     \n");
   for(int i = 0; i < 59; i++){
    printf("=");
}

printf("\n");

printf("\nSelect your diet:\n");
printf(" 1. Vegan\n 2. Vegetarian\n 3. Non-Vegetarian\n");
printf("Your choice: ");
scanf("%d", &p1.pref1.diet);
if (p1.pref1.diet < 1 || p1.pref1.diet > 3) {
printf("\nInvalid Input. Please try again.\n\n");
preference();
return;

}
printf("\nSelect your workout type:\n");
printf(" 1. Yoga\n 2. Home Workout\n 3. GYM\n");
printf("Your choice: ");
scanf("%d", &p1.pref1.workout);
if (p1.pref1.workout < 1 || p1.pref1.workout > 3) {
printf("\nInvalid Input. Please try again.\n\n");
preference();
return;

}
printf("\nSelect your experience level:\n");
printf(" 1. Beginner\n 2. Intermediate\n 3. Advanced\n");
printf("Your choice: ");
scanf("%d", &p1.pref1.experience);
if (p1.pref1.experience < 1 || p1.pref1.experience > 3) {
printf("\nInvalid Input. Please try again.\n\n");
preference();
return;

}
printf("\nPreferences saved successfully!\n");
for(int i = 0; i < 59; i++){
printf("=");
}
printf("\n");
}

void profile() {
 for(int i = 0; i < 59; i++){
    printf("=");
}
printf("\n");
    printf("                     ENTER YOUR DETAILS                     \n");
    for(int i = 0; i < 59; i++){
    printf("=");
}
printf("\n\n");
printf("Enter your name: ");
getchar();
fgets(p1.name, 100, stdin);
printf("Enter your age: ");
scanf("%d", &p1.age);
if (p1.age <= 0 ) {
printf("Invalid age!\n");
return;
}

getchar();
printf("Enter your gender: ");
fgets(p1.gender, 20, stdin);
printf("Enter your height (in metres): ");
scanf("%f", &p1.height);
printf("Enter your weight (in kilograms): ");
scanf("%f", &p1.weight);
float bmi = BMI_cal(p1.height, p1.weight);
printf("\n");
for(int i = 0; i < 59; i++){
    printf("-");
}
printf("\n");
    printf("Your BMI is: %.2f\n", bmi);
    BMI_category(bmi);
    for(int i = 0; i < 59; i++){
    printf("-");}
    printf("\n");
printf("Enter your goal: ");
scanf("%f", &p1.goal);
preference();
}

void save_profile(struct profile p) {
FILE *fp = fopen("user_profile.txt", "w");
if (fp == NULL) {
printf("Error saving file!\n");
return;
}

fprintf(fp, "Name: %s ", p.name);
fprintf(fp, "Age: %d \n", p.age);
fprintf(fp, "Gender: %s", p.gender);
fprintf(fp, "Height: %.2f\n", p.height);
fprintf(fp, "Weight: %.2f\n", p.weight);
fprintf(fp, "Goal Weight: %.2f\n", p.goal);
fprintf(fp, "Diet Choice: %d\n", p.pref1.diet);
fprintf(fp, "Workout Choice: %d\n", p.pref1.workout);
fprintf(fp, "Experience: %d\n", p.pref1.experience);
fclose(fp);
printf("\n Profile saved\n");
}

void load_profile(struct profile *p) {
FILE *fp = fopen("user_profile.txt", "r");
if (fp == NULL) {
return;
}
fscanf(fp, "Name: %[^\n]\n", p->name);
fscanf(fp, "Age: %d\n", &p->age);
fscanf(fp, "Gender: %[^\n]\n", p->gender);
fscanf(fp, "Height: %f\n", &p->height);
fscanf(fp, "Weight: %f\n", &p->weight);
fscanf(fp, "Goal Weight: %f\n", &p->goal);
fscanf(fp, "Diet Choice: %d\n", &p->pref1.diet);
fscanf(fp, "Workout Choice: %d\n", &p->pref1.workout);
fscanf(fp, "Experience: %d\n", &p->pref1.experience);
fclose(fp);
}

void edit_pref(){
printf("Your Current Preferences are \n");
printf("%-22s : ", "Diet");
switch (p1.pref1.diet) {
case 1: printf("Vegan\n"); break;
case 2: printf("Vegetarian\n"); break;
case 3: printf("Non-Vegetarian\n"); break;
}
printf("%-22s : ", "Workout");
switch (p1.pref1.workout) {
case 1: printf("Yoga\n"); break;
case 2: printf("Home Workout\n"); break;
case 3: printf("GYM\n"); break;
}
printf("%-22s : ", "Experience");
switch (p1.pref1.experience) {
case 1: printf("Beginner\n"); break;
case 2: printf("Intermediate\n"); break;
case 3: printf("Advanced\n"); break;
}
preference();
printf("\n===========================================\n");
}
float BMI_cal(float height, float weight) {
return weight / (height * height);
}

void BMI_category(float bmi) {
if (bmi < 18.5)
printf("You are Underweight\n");
else if (bmi >= 18.5 && bmi < 25)
printf("You are in a healthy range\n");
else if (bmi >= 25)
printf("You are Overweight\n");
}

void view_profile() {
if (strlen(p1.name) == 0) {
printf("\nNo profile found. Please create your profile first.\n");
return;
}
float bmi = BMI_cal(p1.height, p1.weight);
printf("\n==========================================================\n");
printf("                      USER PROFILE \n");
printf("===========================================================\n\n");
printf("Name\t\t: %s", p1.name);
printf("\nAge\t\t: %d Years\n", p1.age);
printf("Gender\t\t: %s", p1.gender);
printf("\nHeight\t\t: %.2f m\n", p1.height);
printf("Weight\t\t: %.2f kg\n", p1.weight);
printf("BMI\t\t: %.2f\n\n", bmi);
BMI_category(bmi);
printf("\nGoal Weight\t: %.2f kg\n", p1.goal);
printf("\n========================================================\n");
printf("                      USER PREFERENCES \n");
printf("========================================================\n\n");
printf("Diet\t\t: ");
switch (p1.pref1.diet) {
case 1: printf("Vegan\n"); break;
case 2: printf("Vegetarian\n"); break;
case 3: printf("Non-Vegetarian\n"); break;
}
printf("Workout\t\t: ");
switch (p1.pref1.workout) {
case 1: printf("Yoga\n"); break;
case 2: printf("Home Workout\n"); break;
case 3: printf("GYM\n"); break;
}
printf("Experience\t: ");
switch (p1.pref1.experience) {
case 1: printf("Beginner\n"); break;
case 2: printf("Intermediate\n"); break;
case 3: printf("Advanced\n"); break;
}
printf("\n========================================================\n");
}

void diet(){
switch(p1.pref1.diet) {
case 1:vegan();break;
case 2:vegetarian();break;
case 3:nonvegetarian();break;
default:
printf("\nInvalid choice! Please enter a number between 1 and 3.\n");
break;
}
return ;
}

void vegan(){
printf("\nDay 1:\n");
printf(" Breakfast: Oatmeal with fruits and almond milk\n");
printf(" Lunch: Quinoa salad with chickpeas\n");
printf(" Dinner: Lentil soup with whole grain bread\n");
printf("\nDay 2:\n");
printf(" Breakfast: Avocado toast with soy milk\n");
printf(" Lunch: Tofu stir-fry with vegetables\n");
printf(" Dinner: Vegetable curry with brown rice\n");
printf("\nDay 3:\n");
printf(" Breakfast: Peanut butter oatmeal\n");
printf(" Lunch: Veggie wrap \n");
printf(" Dinner: Chickpea stew with salad\n");
printf("\nDay 4:\n");
printf(" Breakfast: Fruit smoothie\n");
printf(" Lunch: sandwich with soup\n");
printf(" Dinner: Bean chili with quinoa\n");
printf("\nDay 5:\n");
printf(" Breakfast: Green smoothie and nuts\n");
printf(" Lunch: Brown rice with veggies\n");
printf(" Dinner: Tofu curry with salad\n");
printf("\nDay 6:\n");
printf(" Breakfast: Granola with soy milk\n");
printf(" Lunch: Pasta with vegan tomato sauce\n");
printf(" Dinner: Grilled vegetables with lentils\n");
printf("\nDay 7:\n CHEAT DAY XD\n");
}

void vegetarian(){
printf("\nDay 1:\n");
printf(" Breakfast: Paneer sandwich with juice\n");
printf(" Lunch: Dal, rice, and mixed veg\n");
printf(" Dinner: Salad with vegetable soup\n");
printf("\nDay 2:\n");
printf(" Breakfast: Poha with curd\n");
printf(" Lunch: Mixed veg curry with chapati\n");
printf(" Dinner: Khichdi and salad\n");
printf("\nDay 3:\n");
printf(" Breakfast: Upma with tea\n");
printf(" Lunch: Rajma chawal\n");
printf(" Dinner: Vegetable soup and fruit\n");
printf("\nDay 4:\n");
printf(" Breakfast: Paratha with curd\n");
printf(" Lunch: Khichdi with papad\n");
printf(" Dinner: Fruit bowl and salad\n");
printf("\nDay 5:\n");
printf(" Breakfast: Idli with sambar\n");
printf(" Lunch: Chole bhature\n");
printf(" Dinner: Vegetable pulao and curd\n");
printf("\nDay 6:\n");
printf(" Breakfast: Veg sandwich with smoothie\n");
printf(" Lunch: Dal fry with rice\n");
printf(" Dinner: Roti with paneer curry\n");
printf("\nDay 7:\n CHEAT DAY XD\n");
}

void nonvegetarian(){
printf("\nDay 1:\n");
printf(" Breakfast: Boiled eggs and toast\n");
printf(" Lunch: Grilled chicken with vegetables\n");
printf(" Dinner: Fish curry with rice\n");
printf("\nDay 2:\n");
printf(" Breakfast: Omelet with brown bread\n");
printf(" Lunch: Chicken curry with rice\n");
printf(" Dinner: Egg biryani and salad\n");
printf("\nDay 3:\n");
printf(" Breakfast: Scrambled eggs with juice\n");
printf(" Lunch: Tuna sandwich and soup\n");
printf(" Dinner: Mutton curry with chapati\n");
printf("\nDay 4:\n");
printf(" Breakfast: Egg toast with milk\n");
printf(" Lunch: Chicken salad and rice\n");
printf(" Dinner: Prawn curry with roti\n");
printf("\nDay 5:\n");
printf(" Breakfast: Egg curry with brown rice\n");
printf(" Lunch: Grilled fish with veggies\n");
printf(" Dinner: Chicken soup and salad\n");
printf("\nDay 6:\n");
printf(" Breakfast: Boiled eggs and smoothie\n");
printf(" Lunch: Chicken wrap with yogurt\n");
printf(" Dinner: Spicy fish fry with rice\n");
printf("\nDay 7:\n CHEAT DAY XD\n");
}

WorkoutPlan yogaPlans[3] = {
{
{
{"Day 1: Full-Body Detox Flow",
"1. Chair Pose (Utkatasana) - 30 sec",
"2. Plank Pose - 30 sec",
"3. Cobra Pose - 30 sec",
"4. Seated Forward Fold (Paschimottanasana) - 1 min"},
{"Day 2: Core & Belly Fat Focus",
"1. Boat Pose (Navasana) - 3 sets x 30 sec",
"2. Plank to Dolphin Pose - 10 reps",
"3. Bow Pose (Dhanurasana) - 3 x 20 sec",
"4. Bridge Pose (Setu Bandhasana) - 3 x 30 sec"},
{"Day 3: Lower Body Burn",
"1. Warrior I & II - 1 min each side",
"2. Goddess Pose - 45 sec x 2 rounds",
"3. Crescent Lunge - 45 sec each side",
"4. Chair Pose Pulses - 15 rounds"},
{"Day 4: Upper Body & Arms Toning",
"1. Plank variations - 3 x 30 sec",
"2. Chaturanga Dandasana - 10 rounds",
"3. Dolphin Pose - 1 min",
"4. Side Plank - 30 sec each side"},
{"Day 5: Power Yoga Flow",
"1. Sun Salutation (Surya Namaskar) - 3 times",
"2. Warrior III - 30 sec each side",
"3. Chair to Twisted Chair - 10 reps",
"4. Plank to Cobra to Down Dog - 10 reps"},
{"Day 6: Balance & Flexibility",
"1. Tree Pose (Vrikshasana) - 45 sec each side",
"2. Triangle Pose (Trikonasana) - 1 min each side",
"3. Half Moon Pose (Ardha Chandrasana) - 30 sec each side",
"4. Pigeon Pose (Eka Pada Rajakapotasana) - 1 min each side"},
{"Day 7: Rest day!", "", "", "", ""}
}
},
{
{
{"Day 1: Full-Body Detox Flow",
"1. Chair Pose - 2 min",
"2. Plank - 2 min",
"3. Cobra - 2 min",
"4. Seated Forward Fold - 3 min"},
{"Day 2: Core & Belly Fat Focus",
"1. Boat Pose - 7 sets x 30 sec",
"2. Plank to Dolphin Pose - 10 reps",
"3. Bow Pose - 7 sets x 20 sec",
"4. Bridge Pose - 7 sets x 30 sec"},
{"Day 3: Lower Body Burn",
"1. Warrior I & II - 3 min each side",
"2. Goddess Pose - 45 sec x 6 rounds",
"3. Crescent Lunge - 1 min 30 sec each side",
"4. Chair Pose Pulses - 45 rounds"},
{"Day 4: Upper Body & Arms Toning",
"1. Plank variations - 7 sets x 30 sec",
"2. Chaturanga Dandasana - 20 rounds",
"3. Dolphin Pose - 3 min",
"4. Side Plank - 2 min each side"},
{"Day 5: Power Yoga Flow",
"1. Sun Salutation (Surya Namaskar) - 5 times",
"2. Warrior III - 2 min each side",
"3. Chair to Twisted Chair - 20",
"4. Plank to Cobra to Down Dog - 20"},
{"Day 6: Balance & Flexibility",
"1. Tree Pose - 1 min 30 sec each side",
"2. Triangle - 3 min each side",
"3. Half Moon - 3 min each side",
"4. Pigeon - 3 min each side"},
{"Day 7: Rest day!", "", "", "", ""}
}
},
{
{
{"Day 1: Full-Body Detox Flow",
"1. Chair Pose - 4 min",
"2. Plank - 4 min",
"3. Cobra - 4 min",
"4. Seated Forward Fold - 4 min"},
{"Day 2: Core & Belly Fat Focus",
"1. Boat Pose - 10 sets x 30 sec",
"2. Plank to Dolphin Pose - 10 reps",
"3. Bow Pose - 10 sets x 20 sec",
"4. Bridge Pose - 10 sets x 30 sec"},
{"Day 3: Lower Body Burn",
"1. Warrior I & II - 3 min each side",
"2. Goddess Pose - 45 sec x 8 rounds",
"3. Crescent Lunge - 3 min each side",
"4. Chair Pose Pulses - 60 rounds"},
{"Day 4: Upper Body & Arms Toning",
"1. Plank variations - 10 sets x 30 sec",
"2. Chaturanga Dandasana - 20 rounds",
"3. Dolphin Pose - 5 min",
"4. Side Plank - 4 min each side"},
{"Day 5: Power Yoga Flow",
"1. Sun Salutation (Surya Namaskar) - 4 times",
"2. Warrior III - 1 min each side",
"3. Chair to Twisted Chair - 10",
"4. Plank to Cobra to Down Dog - 10"},
{"Day 6: Balance & Flexibility",
"1. Tree Pose - 3 min each side",
"2. Triangle - 3 min each side",
"3. Half Moon - 3 min each side",
"4. Pigeon - 3 min each side"},
{"Day 7: Rest day!", "", "", "", ""}
}
}
};
WorkoutPlan gymPlans[3] = {
{
{
{"Day 1: Leg Day",
"1. Squats - 4 sets x 10 reps",
"2. Walking Lunges - 3 sets x 12 each leg",
"3. Leg Press - 3 sets x 12",
"4. Standing Calf Raises - 4 sets x 15"},
{"Day 2: Shoulder Day",
"1. Overhead Dumbbell Press - 4 sets x 10",
"2. Lateral Raises - 3 sets x 12",
"3. Front Raises - 3 sets x 12",
"4. Arnold Press - 3 sets x 10"},
{"Day 3: Cardio + Core",
"1. Treadmill Intervals - 20 min (1 min run / 1 min walk)",
"2. Mountain Climbers - 3 sets x 30 sec",
"3. Russian Twists - 3 sets x 20",
"4. Plank - 3 sets x 45 sec"},
{"Day 4: Back Day",
"1. Lat Pulldown - 4 sets x 10",
"2. Seated Cable Row - 3 sets x 12",
"3. Dumbbell Deadlift - 3 sets x 10",
"4. Face Pulls - 3 sets x 15"},
{"Day 5: Chest Day",
"1. Bench Press - 4 sets x 10",
"2. Incline Dumbbell Press - 3 sets x 12",
"3. Chest Fly (Cable or Dumbbell) - 3 sets x 12",
"4. Push-ups - 3 sets x 15"},
{"Day 6: Arms Day",
"1. Bicep Curls - 4 sets x 12",
"2. Hammer Curls - 3 sets x 10",
"3. Tricep Dips - 3 sets x 10",
"4. Tricep Pushdowns - 3 sets x 12"},
{"Day 7: Rest day!",
"", "", "", ""}
}
},
{
{
{"Day 1: Leg Day",
"1. Squats - 6 sets x 10",
"2. Walking Lunges - 7 sets x 12 each leg",
"3. Leg Press - 7 sets x 12",
"4. Standing Calf Raises - 6 sets x 15"},
{"Day 2: Shoulder Day",
"1. Dumbbell Press - 6 sets x 10",
"2. Lateral Raises - 7 sets x 12",
"3. Front Raises - 7 sets x 12",
"4. Arnold Press - 7 sets x 10"},
{"Day 3: Cardio + Core",
"1. Treadmill Intervals - 30 min (2 min run / 1 min walk)",
"2. Mountain Climbers - 7 sets x 30 sec",
"3. Russian Twists - 5 sets x 20",
"4. Plank - 7 sets x 45 sec"},
{"Day 4: Back Day",
"1. Lat Pulldown - 6 sets x 10",
"2. Cable Row - 7 sets x 12",
"3. Deadlift - 7 sets x 10",
"4. Face Pull - 7 sets x 15"},
{"Day 5: Chest Day",
"1. Bench Press - 7 sets x 10",
"2. Incline DB - 7 sets x 12",
"3. Chest Fly - 7 sets x 12",
"4. Push-ups - sets x 15"},
{"Day 6: Arms Day",
"1. Bicep Curls - 7 sets x 12",
"2. Hammer Curls - 7 sets x 10",
"3. Tricep Dips - 7 sets x 10",
"4. Pushdowns - 7 sets x 12"},
{"Day 7: Rest day!",
"", "", "", ""}
}
},
{
{
{"Day 1: Leg Day",
"1. Squats - 8 sets x 10",
"2. Walking Lunges - 10 sets x 12 each leg",
"3. Leg Press - 10 sets x 12",
"4. Standing Calf Raises - 8 sets x 15"},
{"Day 2: Shoulder Day",
"1. Dumbbell Press - 8 sets x 10",
"2. Lateral Raises - 10 sets x 12",
"3. Front Raises - 10 sets x 12",
"4. Arnold Press - 10 sets x 10"},
{"Day 3: Cardio + Core",
"1. Treadmill Intervals - 40 min (2 min run / 1 min walk)",
"2. Mountain Climbers - 10 sets x 30 sec",
"3. Russian Twists - 6 sets x 20",
"4. Plank - 10 sets x 45 sec"},
{"Day 4: Back Day",
"1. Lat Pulldown - 8 sets x 10",
"2. Seated Cable Row - 10 sets x 12",
"3. Dumbbell Deadlift - 10 sets x 10",
"4. Face Pulls - 10 sets x 15"},
{"Day 5: Chest Day",
"1. Bench Press - 10 sets x 10",
"2. Incline Dumbbell Press - 10 sets x 12",
"3. Chest Fly - 10 sets x 12",
"4. Push-ups - 10 sets x 15"},
{"Day 6: Arms Day",
"1. Bicep Curls - 10 sets x 12",
"2. Hammer Curls - 10 sets x 10",
"3. Tricep Dips - 10 sets x 10",
"4. Tricep Pushdowns - 10 sets x 12"},
{"Day 7: Rest day!",
"", "", "", ""}
}
}
};
WorkoutPlan homePlans[3] = {
{
{
{"Day 1: Full Body Burn",
"1. Jumping Jacks - 3 sets x 30 sec",
"2. Squats - 3 sets x 15 times se",
"3. Push-ups - 3 sets x 10 times",
"4. Plank - 3 sets x 30 sec"},
{"Day 2: Lower Body (Leg Day)",
"1. Lunges - 3 sets x 12 times each leg",
"2. Glute Bridges - 3 sets x 15times",
"3. Wall Sit - 3 sets x 30 sec",
"4. Calf Raises - 3 sets x 20 times"},
{"Day 3: Core & Abs",
"1. Crunches - 3 x 15",
"2. Leg Raises - 3 x 12",
"3. Russian Twists - 3 sets x 20 times (each side)",
"4. Mountain Climbers - 3 sets x 30 sec"},
{"Day 4: Upper Body (Arms & Chest)",
"1. Incline Push-ups (on bed or chair) - 3 sets x 10 times",
"2. Tricep Dips (use a sturdy chair) - 3 sets x 10 times",
"3. Shoulder Taps (in plank) - 3 sets x 20 times",
"4. Superman Hold - 3 sets x 30 sec"},
{"Day 5: Cardio & Fat Burn",
"1. High Knees - 3 sets x 30 sec",
"2. Burpees - 3 sets x 10 times",
"3. Skater Jumps - 3 sets x 15 times(each side)",
"4. Jump Squats - 3 sets x 12 times"},
{"Day 6: Yoga Stretch & Mobility",
"1. Downward Dog - 3 sets x 30 sec",
"2. Cat-Cow Stretch - 3 sets x 10 times",
"3. Cobra Pose - 3 sets x 30 sec",
"4. Child's Pose - 2 min hold"},
{"Day 7: Rest day!",
"", "", "", ""}
}
},
{
{
{"Day 1: Full Body Burn",
"1. Jumping Jacks - 7 sets x 30 sec",
"2. Squats - 7 sets x 15",
"3. Push-ups - 7 sets x 10",
"4. Plank - 7 sets x 30 sec"},
{"Day 2: Lower Body (Leg Day)",
"1. Lunges - 7 sets x 12",
"2. Glute Bridges - 7 sets x 15",
"3. Wall Sit - 7 sets x 30 sec",
"4. Calf Raises - 7 sets x 20"},
{"Day 3: Core & Abs",
"1. Crunches - 7 x 15",
"2. Leg Raises - 7 x 12",
"3. Russian Twists - 7 sets x 20 times (each side)",
"4. Mountain Climbers - 7 sets x 30 sec"},
{"Day 4: Upper Body (Arms & Chest)",
"1. Incline Push-ups - 7 sets x 10 times",
"2. Tricep Dips - 7 sets x 10 times",
"3. Shoulder Taps - 7 sets x 20 times",
"4. Superman - 7 sets x 30 sec"},
{"Day 5: Cardio & Fat Burn",
"1. High Knees - 7 sets x 30 sec",
"2. Burpees - 7 sets x 10 times",
"3. Skater Jumps - 7 sets x 15 times(each side)",
"4. Jump Squats - 7 sets x 12 times"},
{"Day 6: Yoga Stretch & Mobility",
"1. Downward Dog - 7 sets x 30 sec",
"2. Cat-Cow - 7 sets x 10",
"3. Cobra - 7 sets x 30 sec",
"4. Child's Pose - 2 min"},
{"Day 7: Rest day!",
"", "", "", ""}
}
},
{
{
{"Day 1: Full Body Burn",
"1. Jumping Jacks - 10 sets x 30 sec",
"2. Squats - 10 sets x 15",
"3. Push-ups - 10 sets x 10",
"4. Plank - 10 sets x 30 sec"},
{"Day 2: Lower Body (Leg Day)",
"1. Lunges - 10 sets x 12",
"2. Glute Bridges - 10 sets x 15",
"3. Wall Sit - 10 sets x 30 sec",
"4. Calf Raises - 10 sets x 20"},
{"Day 3: Core & Abs",
"1. Crunches - 10 x 15",
"2. Leg Raises - 10 x 12",
"3. Russian Twists - 1o sets x 20 times (each side)",
"4. Mountain Climbers - 10 sets x 30 sec"},
{"Day 4: Upper Body (Arms & Chest)",
"1. Incline Push-ups - 10 sets x 10 times",
"2. Tricep Dips - 10 sets x 10 times",
"3. Shoulder Taps - 10 sets x 20",
"4. Superman Hold - 10 sets x 30 sec"},
{"Day 5: Cardio & Fat Burn",
"1. High Knees - 10 sets x 30 sec",
"2. Burpees - 10 sets x 10 times",
"3. Skater Jumps - 10 sets x 15 times(each side)",
"4. Jump Squats - 10 sets x 12 times"},
{"Day 6: Yoga Stretch & Mobility",
"1. Downward Dog - 10 sets x 30 sec",
"2. Cat-Cow - 10 sets x 10",
"3. Cobra - 10 sets x 30 sec",
"4. Child's Pose - 5 min"},
{"Day 7: Rest day!",
"", "", "", ""}
}
}
};

void printPlanLevel(WorkoutPlan planLevel) {
for (int d = 0; d < 7; d++) {
if (strlen(planLevel.plan[d][0]) > 0) {
printf("\n%s\n\n", planLevel.plan[d][0]);
}
for (int e = 1; e < 5; e++) {
if (strlen(planLevel.plan[d][e]) == 0) continue;
printf("%s\n", planLevel.plan[d][e]);
}
}
}
void showYogaByLevel(int level) {
if (level < 0 || level > 2) { printf("Invalid level\n"); return; }
printPlanLevel(yogaPlans[level]);
}
void showGymByLevel(int level) {
if (level < 0 || level > 2) { printf("Invalid level\n"); return; }
printPlanLevel(gymPlans[level]);
}
void showHomeByLevel(int level) {
if (level < 0 || level > 2) { printf("Invalid level\n"); return; }
printPlanLevel(homePlans[level]);
}
void yoga_repl() {
int lvl = p1.pref1.experience - 1;
if (lvl < 0 || lvl > 2) { printf("Invalid experience level\n"); return; }
showYogaByLevel(lvl);
}

void gym_repl() {
int lvl = p1.pref1.experience - 1;
if (lvl < 0 || lvl > 2) { printf("Invalid experience level\n"); return; }
showGymByLevel(lvl);
}

void home_repl() {
int lvl = p1.pref1.experience - 1;
if (lvl < 0 || lvl > 2) { printf("Invalid experience level\n"); return; }
showHomeByLevel(lvl);
}

void workout() {
switch(p1.pref1.workout) {
case 1: yoga_repl(); break;
case 2: home_repl(); break;
case 3: gym_repl(); break;
default: printf("Invalid choice\n");
}
}

void trackDailyProgress() {
FILE *fp;
fp = fopen("daily_progress.txt", "a");
if (fp == NULL) {
printf("Error opening file!\n");
return;
}
int day;
char steps, water, exercise, sleep, diet;
printf("Enter Day Number: ");
scanf("%d", &day);
printf("Did you complete your step goal today? (Y/N): ");
scanf(" %c", &steps);
printf("Did you drink enough water today? (Y/N): ");
scanf(" %c", &water);
printf("Did you do exercise today? (Y/N): ");
scanf(" %c", &exercise);
printf("Did you sleep well last night? (Y/N): ");
scanf(" %c", &sleep);
printf("Did you follow a healthy diet today? (Y/N): ");
scanf(" %c", &diet);
fprintf(fp, "Day %d | Steps: %c | Water: %c | Exercise: %c | Sleep: %c | Diet: %c\n",
day, steps, water, exercise, sleep, diet);
fclose(fp);
}

void viewProgress() {
FILE *fp;
char line[2000];
int isEmpty = 1;
fp = fopen("daily_progress.txt", "r");
if (fp == NULL) {
printf("No progress saved.\n");
return;
}
printf("\n--------------------- YOUR SAVED PROGRESS --------------------\n\n");
while(fgets(line, sizeof(line), fp)) {
isEmpty = 0;
printf("%s", line);
}
if (isEmpty) {
printf("No progress saved.\n");
}
else {
printf("\nY means YES\nN means NO\n");
}
fclose(fp);
}


void resetProgress() {
FILE *fp;
fp = fopen("daily_progress.txt", "w");
if (fp == NULL) {
printf("Error opening file!\n");
return;
}
fclose(fp);
}

void clearScreen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

void pause(){
printf("Press Enter to continue");
getchar();
getchar();
}

void deleteprofile() {
FILE *fp = fopen("user_profile.txt", "w");
if (fp == NULL) {
printf("No profile found to delete.\n");
return;
}
fclose(fp);
if (remove("user_profile.txt") == 0) {
printf("Profile Deleted successfully!\n");
} else {
printf("Error deleting profile.\n");
}
p1.age = 0;
p1.height = 0;
p1.weight = 0;
p1.goal = 0;
strcpy(p1.name, "");
strcpy(p1.gender, "");
p1.pref1.diet = 0;
p1.pref1.workout = 0;
p1.pref1.experience = 0;
resetProgress();
}
