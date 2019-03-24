#include<stdio.h>
#include <stdlib.h>

int fib(int n,int k)
{
	    int a=0;
		    int b =0;

			    if(k == 1 )
					    {
							        a = 0;
									        b = 1;
											    }
				    else
						    {
								        a = 1;
										        b = 0;
												    }

					    if(n==0)
							        return b;
						    else if (n==1)
								        return a;
							    else
									        return fib(n-1,k) + fib(n-2,k);
}

int main()
{
	    int a, n;
		    int i =0;
			    int temp =0;
				    int *arr;

					    scanf("%d", &a);
						    temp = a*2;

							    arr = (int*)malloc(sizeof(int)*temp);

								    for(i=0; i<a; i++)
										    {
												        scanf("%d", &n);
														        arr[2*i]=fib(n,1);
																        arr[2*i-1]=fib(n,0);
																		    }

									    for(i=0; i<a; i++)
											    {
													        printf("%d %d\n",arr[2*i],arr[2*i-1]);
															    }
											free(arr);
													return 0;

}
