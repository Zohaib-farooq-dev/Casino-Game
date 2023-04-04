//Casino Game using basic concepts of programming in C++.
//it includes the use of windows.h ,conio.h ,cstdlib important header files extract from C++ standard library.
//In this game i have made two modes 1. Soloplay 2. Play with Friends.
//Player can play game using two methods.
//Either he can guess the number or tell about the number that it is even or odd.
//Same methodology used in both modes.

#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//prototypes of functions defined after the main function
void display();
void rules();
void soloplay();
void multiplayer();


int main()
{
    //declaring variables
    int n;
    int count=1;
    char s;

    //loop to run the game till the user wants to play game
   do
   {
       system("cls");
       display();//function which will display the name of the game
       rules();//function defining the rules of the game

       do//loop to validate the input
       {
           if(count==1)
           {
               //asking from the user whether he wants to play in  solo mode or want to play with friends
               cout<<"\n In which mode you want to play"
                   <<"\n 1. Solo Play"
                   <<"\n 2. Play with friend"
                   <<"\n Please enter 1 for soloplay and 2 for playing with friends \n";
               cin>>n;
           }
           else
           {
               cout<<"Your input is invalid"
                   <<"\n Please enter 1 for soloplay and 2 for playing with friends \n";
               cin>>n;
           }
            count++;
       }
       while(n<1||n>2);


       //condition to check which function should be called
       if(n==1)
       {
           soloplay();//function which will play ther game in solomode
       }
       else if(n==2)
       {
           multiplayer();//function which will play the game in  multimode
       }

       //asking the user that he wants to play again or not
       cout<<"Do you want to play again y/n"<<endl;
       cin>>s;
       if(s=='y')
       {
           count=1;
       }
   }
   while(s=='y');

    return 0;
}
void display()//function to display the name of the game
{

    string var;

    var="\n\n"
        "***************************************************************************************"
        "\n"
        "\n   ****       *       *********      ***********      **     **          **********"
        "\n **          * *      ***                ***          ** *   **         **        **"
        "\n**          *   *     *********          ***          **  *  **        **          **"
        "\n **        *******          ***          ***          **   * **         **        **"
        "\n   ****   *       *   *********      ***********      **     **          **********"
        "\n"
        "\n***************************************************************************************";

        for(int i=0;i<var.size();i++)//loop to print the string variable character by character
        {
            //calling a sleep function
            Sleep(10);
            cout<<var[i];
        }
}
void rules()//function printing the rules of the game
{
    system("cls");//function defined in conio.h header file is called to clear the screen

    cout<<"\n\n\n"<<"\t\t\t\t"<<setfill('*')<<setw(50)
        <<"\n\t\t\t\t\t   "<<"Rules of the Game"<<endl
        <<"\t\t\t\t"<<setfill('*')<<setw(41)<<"*";

        //printing rules of the game
    cout<<"\n\n\n"<<setfill('*')<<setw(170)
        <<"\n\n\t 1. You have to choose any number between 1-10."
        <<"\n\t 2. Or you can choose whether the number is even or odd."
        <<"\n\t 3. If you win you will get 10 times of that amount on which you bet."
        <<"\n\t 4. And if you lose you will lost your money."
        <<"\n\n"<<setfill('*')<<setw(125)<<"*   \n\n";
}
void soloplay()//function to play game in solomode
{
    //declaring variables
    string name;
    int amount;
    int bet;
    int n,num, count1=1,ball;
    bool flag;
    //calling the functions so that every time program runs a random number generate,
    //these functions are defined in cstdlib header file
    srand(time(0));
    ball=rand()%10+1;

    cout<<"Enter player's name \n";//asking the name of the player from the user
    cin>>name;
    getline(cin,name);

    cout<<"How much amount you have $ \n";//asking amount that the user have
    cin>>amount;

    cout<<"On how much amount you want to bet $ \n";//asking amount on which user wants to bet
    cin>>bet;

    if(bet>amount)//condition to check that betv amount should be less than total amount player have
    {
        do
        {
            cout<<"You don't have enough money to bet \n"
                <<"Please bet on less amount \n";
            cin>>bet;
        }
        while(bet>amount);

    }

    do//loop to validate the input
    {
        if(count1==1)
        {
            //asking user that through which method he wants to play
            cout<<"Now please choose your method of playing \n"
                <<"\t 1. You can guess the number between 1 & 10"
                <<"\n\t 2. You can choose that number is even"
                <<"\n\t 3. You can choose that number is odd  \n";
            cin>>n;
        }
        else
        {
            cout<<"Your input is invalid"
                <<"\n Please enter no between 1 & 3 \n";
            cin>>n;
        }
        count1++;
    }
    while(n<1||n>3);


    if(n==1)//multiple if-else to play game according to the method user wants
    {
        //asking from the user to enter his guess number
        cout<<"Enter your guess number \n" ;
        cin>>num;
        if(num==ball)//condition to check that user has guess the number or not
        {
            flag=true;
        }
        else
        {
            flag=0;
        }

    }
    else if(n==2)
    {
        if(ball%2==0)//condition to check the random number is even or not
        {
            flag=true;
        }
        else
        {
            flag=0;
        }

    }
    else if(n==3)
    {
        if(ball%2!=0)//condition to check the random number is odd or not
        {
            flag=true;
        }
        else
        {
            flag=0;
        }

    }

    if(flag==1)
    {
        cout<<"Congratulations ! You Won !\n"
            <<"And you have won $ :  "<<bet*10<<endl;
        amount=amount+(bet*10);
    }
    else
    {
        cout<<"AH ! You Lost ! \n";
        amount=amount-bet;
    }

    //printing the total amount of the player after playing a game
    cout<<"Now your total amount is :  "<<amount<<endl;

}
void multiplayer()//function which will play the game in multi mode
{
    //declaring variables
    string name1,name2;
    int amount1,amount2;
    int bet1,bet2;
    int n1,n2,num1,num2,count1=1,ball;
    bool flag1,flag2;
    //calling the functions so that every time program runs a random number generate,
    //these functions are defined in cstdlib header file
    srand(time(0));
    ball=rand()%10+1;
    cout<<ball<<endl;

    //asking the names of player from the user
    cout<<"Enter player 1's name \n";
    cin>>name1;
    getline(cin,name1);

    cout<<"Enter player 2's name \n";
    cin>>name2;
    getline(cin,name2);


    //asking from the players their total an bet amount
    cout<<"**********"<<"Player 1 :"<<"**********  \n";

    cout<<"How much amount you have $ \n";
    cin>>amount1;

    cout<<"On how much amount you want to bet $ \n";
    cin>>bet1;

    if(bet1>amount1)
    {
        do//loop to validate the bet amount
        {
            cout<<"Player 1 don't have enough money to bet \n"
                <<"Please bet on less amount \n";
            cin>>bet1;
        }
        while(bet1>amount1);

    }

    cout<<"**********"<<"Player 2 :"<<"**********  \n";

    cout<<"How much amount you have $ \n";
    cin>>amount2;

    cout<<"On how much amount you want to bet $ \n";
    cin>>bet2;

   if(bet2>amount2)
    {
        do//loop to validate the bet amount
        {
            cout<<"Player 2  don't have enough money to bet \n"
                <<"Please bet on less amount \n";
            cin>>bet2;
        }
        while(bet2>amount2);

    }
    if(bet1!= bet2 ){
        do{
            if(bet1>bet2){
                cout<<" Bet amount should be equal. Either Player1 reduce his bet amount "
                    <<"or Player2 increase his bet amount\n ";


                    cout<<"Player1 enter your bet amount\n";
                    cin>>bet1;
                    cout<<"Player2 enter your bet amount\n";
                    cin>>bet2;
            }else{
                 cout<<" Bet amount should be equal. Either Player1 increase his bet amount "
                    <<"or Player2 reduce  his bet amount\n";


                    cout<<"Player1 enter your bet amount\n";
                    cin>>bet1;
                    cout<<"Player2 enter your bet amountn";
                    cin>>bet2;
            }
        }while(bet1!=bet2);
    }

    do//loop to validate the input entered by user
    {
        if(count1==1)
        {
            cout<<"You both have to choose same method \n"
                <<"Either you can guess the number or can say about even/odd \n"
                <<"Now please choose your method of playing \n"
                <<"\t 1. You can guess the number between 1 & 10"
                <<"\n\t 2. You can choose that number is even"
                <<"\n\t 3. You can choose that number is odd  \n";

            cout<<"Player 1 enter your choice\n";
            cin>>n1;
            cout<<"Player 2 enter your choice\n";
            cin>>n2;
        }
        else
        {
            cout<<"Your input is invalid"
                <<"\n Please enter no between 1 & 3 \n";

            cout<<"Player 1 enter your choice\n";
            cin>>n1;
            cout<<"Player 2 enter your choice\n";
            cin>>n2;

        }
        count1++;
    }
    while((n1<1||n1>3)||(n2<1||n2>3) );

   //multiple if to play the game according to the method user wants
    if(n1==1&&n2==1)
    {
        cout<<"Player 1 : \n"
            <<"Enter your guess number \n" ;
        cin>>num1;

        cout<<"Player 2 : \n"
            <<"Enter your guess number \n" ;
        cin>>num2;

        //condition to check which player has guess the number
        if(num1==ball)
        {
            flag1=true;
        }
        else
        {
            flag1=false;
        }

        if(num2==ball)
        {
            flag2=true;
        }
        else
        {
            flag2=false;
        }

    }
    else if(n1==2||n2==2)
    {
        if(ball%2==0)//condition to check that the random number is even or not
        {
            if(n1==2)
            {
                flag1=true;
            }else
            {
                flag2=true;
            }
        }

    }
    else if(n1==3&&n2==3)
    {
        if(ball%2!=0)//condition to check that the random number is odd or not
        {
            if(n1==3)
            {
                flag1=true;
            }else
            {
                flag2=true;
            }
        }

    }

    if(flag1==true)
    {
        cout<<"Congratulations ! Player 1 has Won !\n"
            <<"And Player 1 have won $ :  "<<bet1*10<<endl;
        amount1=amount1+(bet1*10);
    }
    else
    {
        cout<<"AH ! Player 1 has Lost ! \n";
        amount1=amount1-bet1;
    }

    if(flag2==true)
    {
        cout<<"Congratulations ! Player 2 has Won !\n"
            <<"And Player 2 have won $ :  "<<bet1*10<<endl;
        amount2=amount2+(bet2*10);
    }
    else
    {
        cout<<"AH ! Player 2 has Lost ! \n";
        amount2=amount2-bet2;
    }

    //printing the total amount of the player after playing a game
    cout<<"Now total amount of player 1 is :  "<<amount1<<endl;
    cout<<"Now total amount of player 2 is :  "<<amount2<<endl;


}

