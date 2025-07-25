#include<stdio.h>
#include<string.h>

#define MAX_USER  10 
#define CREDENTIAL 50 

typedef struct users {

  char name[ CREDENTIAL];    // stored name form registration 
  char password[ CREDENTIAL]; // stored password from registration 

} users;

  users users_index[MAX_USER]; // array for multiple user data 

    int  user_count=0; // for all time next user 


int Rigester_user ();
int  login_user ();
void fix_fgets_input(char*);
void password_input(char*);

int main(){
    int option ;
    int user_index ; //carry number of login user index
   
    while(1)
    {
printf ("1.Register\n");
printf ("2.login\n");
printf ("3.exit\n");
printf ("choces a option : ");
scanf("%d",&option);
getchar();
    
     switch(option){
     
     case 1:
    {
     Rigester_user();
      break;
    }
    case 2:
    {
      user_index = login_user ();
     if (user_index >= 0)
     {
   printf("login successful  welcowe !  %s\n\n",users_index[user_index].name);
     }
  else
   {
    printf("login failed ! incorrent user name or password \n \n");
  }
  break;

    }
    case 3:
    {
printf ("\nexit the program !\n\n");
    return 0;
    }
    default:
    {
        printf ("\n select valid option ! \n\n");
    }
  }
   printf("=================================================  \n");
  }
 
    return 0;
}
int Rigester_user ()
{ 
if (user_count==MAX_USER)
{
 printf("maximum %d are supported ! no more registrations allowed !!!!!!",MAX_USER);
return 0;
}

int new_index;
new_index = user_count;

  printf("\n============please enter your detail=============  \n");

printf("please enter your name : ");

fgets(users_index[user_count].name, CREDENTIAL,stdin);
fix_fgets_input(users_index[user_count].name) ;

password_input(users_index[user_count].password );

printf("Rigestation successful  welcowe ! : %s\n",users_index[user_count].name);
 printf("\n");
user_count++;


}

int login_user (){
char username[CREDENTIAL];
char password[CREDENTIAL];

   printf("\n============please enter your detail=============  \n");
  printf("please enter your name : ");
fgets(username, CREDENTIAL,stdin);
fix_fgets_input(username) ;

password_input(password  );

for(int i=0;i<=user_count;i++){
if( 
  strcmp(username ,users_index[i].name) == 0 &&
strcmp( password ,users_index[i].password) == 0 
){
  //printf("\nlogin successful ! welcowe ! : \n%s\n",username);
   return i;
}

 }

return -1;

}

void fix_fgets_input(char* string )
 {
   int index;
index =  strcspn (string ,"\n");
string[index]='\0';
}

void password_input(char* password ){
  
  printf("\nplease enter your password : ");
fgets(password, CREDENTIAL,stdin);
printf("\n");
fix_fgets_input(password) ;

}

