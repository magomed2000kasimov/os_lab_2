#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <stdbool.h>

   
unsigned long long fact(int n){

    if (n == 0){
        return 1;
    }
    else {    
        int write_fd[2];
        if (pipe(write_fd)){
            printf("Error: pipe\n");
            exit(1);
        }
        pid_t proc = fork();

        if (proc < 0){
            printf("Error: fork\n");
            exit(1);
        }

        int wt;
        wait(&wt);
         if (proc == 0){
            unsigned long long res;
            res = fact(n - 1);
            unsigned long long count;
            count = write(write_fd[1], &res, sizeof(int));

            exit(0);
        }

        if (proc > 0) {
            unsigned long long res;
            unsigned long long count;
        
            count = read(write_fd[0], &res, sizeof(int));
            return n * (res); 
        }    
    }
}



int main(){
	char a[132] = { 'I','n','s','t','r','u','c','t','i','o','n','.','\n',
                    'E','n','t','e','r',' ','o','n','l','y',' ','o','n','e',' ','n','o','n','n','e','g','a','t','i','v','e',' ',
                    'i','n','t','e','g','e','r',' ','n','u','m','b','e','r',' ','l','e','s','s',' ','t','h','a','n',
                    ' ','1','4','.',' '
                    ,'I','n',' ','c','a','s','e',' ','o','f',' ','i','n','c','o','r','r','e','c','t',' ','i','n','p','u','t',',',' ','t','h','e',' ','p','r','o'
                    ,'g','r','a','m',' ','w','i','l','l',' ','s','i','m','p','l','y',' ','t','e','r','m','i','n','a','t','e',':','\n' }; 
    for ( int i = 0 ; i < 132 ; ++i ) {
            write(STDOUT_FILENO,&a[i],sizeof(char));
    }
        
        
    int flag = 0,flagPlus = 0,flagTabs = 0,flagNumber = 0;
	int n = 0;
	char c;
        while(true) {
	read(STDIN_FILENO,&c,1);
	if (c <= '9' && c >= '0') {
	flagPlus++;
    flagNumber++;
    n *= 10;
	n += c - '0';
    continue;
	}
	if (c=='\n')
	break;
    if (c == '+' && flagPlus == 0) {
            flagPlus++;
            continue;
    }
    if ((c == ' ' || c == '\t') && (flagTabs == 0)) {
            continue;
    } 
    else 	
	++flag;
	} 
    if (flag != 0 || flagNumber == 0) {
        return 0;
        }
	if (flag > 13)
			return 0;
	unsigned long long k;
    k=fact(n);
    char res[17],res2[17];
	int i=0;
	while (k!=0){
	res[i]=k%10;
	k/=10;
	++i;}
	char tmp;
	for (int j = 0;j < i;++j){
		res2[j]=res[i-j-1];}
	for (int j = 0;j < i;++j){
	tmp = res2[j]+'0';
	write(STDOUT_FILENO,&tmp,sizeof(char));
    }
    char enter = '\n';
    write(STDOUT_FILENO,&enter,sizeof(char));
	return 0;
}

