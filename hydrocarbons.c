#include <stdio.h>
//είναι αρκετά που πρέπει να σου εξηγήσω και πρέπει να στα δείξω ένα ένα
#define SIZE 4
int main()
{
	int ar1[SIZE]={0},ar2[SIZE]={0},ar3[SIZE]={0};
	float ar4[SIZE],apodotikotita,temp; //?
	int i=0,n,k=-1,j;//?
	FILE *fptr;
	
	if(fptr=fopen("hydrocarbons.in", "r")){
		fscanf(fptr, "%d",&n);
		
		while(i<n){ //?
			fscanf(fptr, "%d",&ar1[i]);
			fscanf(fptr, "%d",&ar2[i]);
			fscanf(fptr, "%d",&ar3[i]);
			
			apodotikotita=ar1[i]-ar1[i]*(ar2[i]/3000.0)-ar3[i]*ar1[i]/40.0;
			if (apodotikotita>0){
				k++;//?
				ar4[k]=apodotikotita;//?
			}
			i++;//?
		}
		
		
		 //?----------<
		for(i=1;i<=k;i++){
			for(j=k;j>=i;j--){
				if(ar4[j]>ar4[j-1]){
					temp=ar4[j];
					ar4[j]=ar4[j-1];
					ar4[j-1]=temp;
				} 
			}
		}
		//?--------->
		
		fptr=fopen("hydrocarbons.out", "w");
                fprintf(fptr,"%d\n%d %d %d",i,k,j,n);

	}
	else{
		printf("error while opening file\n");
	}
	return 0;
}
