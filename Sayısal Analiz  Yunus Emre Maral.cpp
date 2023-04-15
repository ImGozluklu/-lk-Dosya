/*
    Yunus Emre Maral 210106109010   
    
    Hocam kodun bir kýsmýný kendim yazdým bir kýsmýnýda internetten yardým aldým
	cok zorlandýgým yerlerde þimdiden degerlendirmeniz için teþekkürler.
	 
	Ben kendim tek tek denedigimde bir sýkýntý yaratmadý ve çözdü denklemleri lütfen
	yönlendirmeleri dikkatli okuyun gauss jordanda b matrisinide a matrisine birleþik alýyorum 
	tekrardan teþekkür ederim.
    
*/
#include <iostream>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10
using namespace std;


// fonksiyonlar
int determinant( int matrix[10][10], int n) {
   int det = 0;
   int submatrix[10][10];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return  (float) det;
}



int main(){
	int n, i, j;
    int matrix[10][10],sonuc[10][1],matris1[10][10],matris2[10][10],matris3[10][10],matris4[10][10];
	int q;
	cout<<"1.Cramer Yontemi"<<endl;
	cout<<"2.Gauss Jordan Yontemi"<<endl;
	cout<<"3.Cholesky Yontemi	"<<endl;
	cout<<"Lutfen Yontemin Numarasini Giriniz"<<endl;
	cin>>q;
	
	
	if(q==1){
	
	/*
       Cramer Methodu !! 

    */
		
		cout << "NxN matrisin n degerini giriniz:  "<<endl;
   cin >> n;
   cout << "Matris elemanlarini giriniz: "<<endl;
   for (i = 0; i < n; i++){
  
   for (j = 0; j < n; j++){
   cout<<"Matris ["<<i<<"]["<<j<<"]";
   cin >> matrix[i][j];
   
   }
    }
   
   cout<<"Girilen Matris : "<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
      cout << matrix[i][j] <<" ";
      cout<<endl;
   }
   cout <<"Sonuc Matrisini Giriniz:  "<<endl;
   for(i=0;i<n;i++){
   	cin>>sonuc[i][0];
   }
   cout<<"Sonuc Matrisi: "<<endl;
   for(i=0;i<n;i++){
   	cout<<sonuc[i][0]<<endl;
   }
   cout<<endl;
   
   for(i=0;i<n;i++){
   	for(j=0;j<n;j++){
   		matris1[i][j]=matrix[i][j];
   		matris2[i][j]=matrix[i][j];
   		matris3[i][j]=matrix[i][j];
   		matris4[i][j]=matrix[i][j];
   		
	   }
   }

   for(i=0;i<n;i++){
   	 
   	 matris1[i][0]=sonuc[i][0];
   	 matris2[i][1]=sonuc[i][0];
   	 matris3[i][2]=sonuc[i][0];
   	 matris4[i][3]=sonuc[i][0];
      
   }

   
   
   
   
   cout<<"Determinant detA   "<< determinant(matrix, n)<<endl;
   cout<<"Determinant detA1  "<<determinant(matris1,n)<<endl;
   cout<<"Determinant detA2  "<<determinant(matris2,n)<<endl;
   cout<<"Determinant detA3  "<<determinant(matris3,n)<<endl;
   if(n>3){
   
   cout<<"Determinant detA4  "<<determinant(matris4,n)<<endl;
   
   }
   
   float x1,x2,x3,x4;
   
   
   x1=(float)(determinant(matris1,n))/(determinant(matrix, n));
   x2=(float)(determinant(matris2,n))/(determinant(matrix, n));
   x3=(float)(determinant(matris3,n))/(determinant(matrix, n));
   x4=(float)(determinant(matris4,n))/(determinant(matrix, n));
   
  
    cout<<"X1 = "<<x1<<endl;
    cout<<"X2 = "<<x2<<endl;
    cout<<"X3 = "<<x3<<endl;
    if(n>3){

    cout<<"X4 = "<<x4<<endl;
   	}
		
	}
		
	else if(q==2){
		
/*
 Gauss Jordan Methodu !!

*/
		
		float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n;

     /* Sabit nokta gösteriminde kesinlik ayarlama ve kayan nokta deðerleri yazma */
     cout<< setprecision(3)<< fixed;

	 /* Girdiler */
	 /* nxn matristeki n degeri yani boyut alýnýr */
	 cout<<"NxN matristeki n degerini giriniz: ";
	 cin>>n;

	 /* 2. Reading Augmented Matrix */
	 cout<<"Bilinmeyenleri giriniz n+1. sutun sonuc matrisinin (B matrisinin) sutunudur ! : "<< endl;
	 
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"a["<< i<<"]"<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }
    /* Gauss Jordan Uygulanmasý */
     for(i=1;i<=n;i++)
     {
          if(a[i][i] == 0.0)
          {
               cout<<"Matematiksel hata! Köþegen 0 olamaz!";
               exit(0);
          }
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    ratio = a[j][i]/a[i][i];
                    for(k=1;k<=n+1;k++)
                    {
                        a[j][k] = a[j][k] - ratio*a[i][k];
                    }
               }
          }
     }
     /* Sonuc elde ediliyor */
     for(i=1;i<=n;i++)
     {
        x[i] = a[i][n+1]/a[i][i];
     }

	 /* Çözüm gösteriliyor */
	 cout<< endl<<"Cozum: "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
		
		
	}
	else if(q==3){
		// Chalosky methodu 
		
		int n,i,k,j,p;
    float a[10][10],l[10][10]={0},u[10][10]={0},sum,b[10],z[10]={0},x[10]={0};
    
    cout<<"NxN Matrisinde n degerini giriniz ! ";
    cin>>n;
    cout<<"Bilinmeyenleri giriniz : ";
    for(i=1;i<=n;i++)
    {
        cout<<"\nSira "<<i<<"  ";
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    }
    cout<<"Sonuc Matrisini Giriniz"<<endl;
    for(i=1;i<=n;i++)
        cin>>b[i];
    //********** LU ayrýstýrma *****//
    for(k=1;k<=n;k++)
    {
        u[k][k]=1;
        for(i=k;i<=n;i++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }

        for(j=k+1;j<=n;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }
    //******** Displaying LU matrix**********//
    cout<<endl<<endl<<"LU Matrisi  "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<l[i][j]<<"  ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<u[i][j]<<"  ";
        cout<<endl;
    }

    //***** Z bulunuypr; LZ=b*********//

    for(i=1;i<=n;i++)
    {                                        
        sum=0;
        for(p=1;p<i;p++)
        sum+=l[i][p]*z[p];
        z[i]=(b[i]-sum)/l[i][i];
    }
    //********** X Bulunuyor; UX=Z***********//

    for(i=n;i>0;i--)
    {
        sum=0;
        for(p=n;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(z[i]-sum)/u[i][i];
    }
    //***********Sonuc Gosterimi **************//
    cout<<endl<<"Sonuc Gosterimi"<<endl;
    for(i=1;i<=n;i++)
        cout<<"X"<<i<<": "<<x[i]<<endl;
		
		
	}
	else 
	{
		cout<<"Yanlis girdiniz!"<<endl;
	}
	

	
	
	return 0;
}
