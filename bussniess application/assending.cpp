#include <iostream>
#include <windows.h>
using namespace std;

main()
{
   int arr[4]={2,5,1,7};
   int temp;
   

   for(int i=0;i<4;i++)
	{		
		for(int j=i+1;j<4;j++)
		{
			if(arr[i]>arr[j])
			{
				temp  =arr[i];
				arr[i]=arr[j];                       
				arr[j]=temp;
				cout<<arr[j]<<" ";
			}
		}
	
   }
   cout<<endl;
   for(int i = 0 ; i<4; i++)
   {
    cout<<arr[i]<<" ";
   }
}