#include <stdio.h>
#include <string.h>


int main(){
  char input[100];
  char output[100];
  int num_flag=0;
  int i;
  int j=0;
  printf("Enter Text: ");
  fgets(input,100,stdin);
  printf("\nString Length %lu, text: %s\n",strlen(input),input);
  for(i=0;i<strlen(input);i++){
    if((input[i]>64)&&(input[i]<91)){//uppercase
      output[j]='u';
      j++;
      output[j]=input[i];
      num_flag=0;
    }

    if((input[i]>96)&&(input[i]<123)){  //lowercase
      output[j]=input[i]-32;            //convert to uppercase
      num_flag=0;
    }

    if((input[i]>47)&&(input[i]<58)){//number
      if(num_flag==0){
        output[j]='n';
        j++;
      }
      output[j]=input[i];
      num_flag=1;
    }

    //and search
    if((input[i]==65)||(input[i]==97)){//A OR a
      if((input[i+1]==78)||(input[i+1]==110)){
        if((input[i+2]==68)||(input[i+2]==100)){  //found a AND
          output[j]='a';
          j++;
          i=i+3;    //escape AND
          num_flag=0;
        }
      }
    }

    //anything else copy over
    if(!((input[i]>47)&&(input[i]<58))&&!((input[i]>64)&&(input[i]<91))&&!((input[i]>96)&&(input[i]<123))){
      output[j]=input[i];
      num_flag=0;
    }

    j++;

  }
  output[j]='\0'; //NULL terminator
  printf("\noutput: %s\n",output);


  return 0;
}
