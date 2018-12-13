#include<iostream>
#include<conio.h>

using namespace std;

struct node{
	int no;
	string nama;
	string posisi;
	node *next;
};

class list {
	node *head, *tail;
	public:
		list(){
			head=tail=NULL;
		}
		void enqueue();
		void dequeue();
		void tampil();
};

void list::enqueue()
{
   int no;
   string nama;
   string posisi;
   struct node *ptr;
   cout<<endl;
   cout<<"Data Pemain Bola"<<endl;
   cout<<"-----------------"<<endl;
   cout<<"Masukan No Punggung : ";
   cin>>no;
   cout<<"Masukan Nama : ";
   cin.ignore();
   getline(cin,nama);
   cout<<"Masukan Posisi : ";
   getline(cin,posisi);
   ptr=new node;
   ptr->no=no;
   ptr->nama=nama;
   ptr->posisi=posisi;
   ptr->next=NULL;
   if(head==NULL)
      head=ptr;
   else
      tail->next=ptr;
   tail=ptr;
   cout<<"data dengan no punggung "<<no<<" nama "<<nama<<" posisi "<<posisi<<" telah masuk dalam antrian";
   getch();
}

void list::dequeue()
{
   if(head==NULL)
   {
   	  cout<<endl;
      cout<<"QUEUE KOSONG!";
      getch();
      return;
   }
   struct node *temp;
   temp=head;
   head=head->next;
   cout<<"data dengan no punggung "<<temp->no<<" nama "<<temp->nama<<" posisi "<<temp->posisi<<" telah dihapus dari antrian";
   delete temp;
   getch();
}

void list::tampil()
{
   struct node *ptr1=head;
   if(head==NULL)
   {
      cout<<"QUEUE KOSONG!"<<endl;
      getch();
      return;
   }
   cout<<"Isi Antrian"<<endl;
   while(ptr1!=NULL)
   {
      cout<<ptr1->no<<" ->"<<ptr1->nama<<" ->"<<ptr1->posisi;
      cout<<endl;
      ptr1=ptr1->next;
   }
   getch();
}

int main()
{
   system("cls");
   list q;
   int pil;
   while(1)
   {
   	  cout<<endl;
   	  cout<<"-------------------------------------------"<<endl;
      cout<<"\tQUEUE MENGGUNAKAN LINKED LIST"<<endl;
      cout<<endl;
      cout<<"1. Enqueue"<<endl;
	  cout<<"2. Dequeue"<<endl;
	  cout<<"3. Tampil"<<endl;
	  cout<<"4. EXIT"<<endl;
      cout<<"Pilih (1-4): ";
      cin>>pil;
      cout<<endl;
      switch(pil)
      {
       case 1:
	  q.enqueue();
	  break;
       case 2:
	  q.dequeue();
	  break;
       case 3:
	  q.tampil();
	  break;
       case 4:
	  exit(0);
	  break;
       default:
	  cout<<"Pilihan anda salah!!";
	  getch();
	  break;
       }
   }
   return 0;
}
