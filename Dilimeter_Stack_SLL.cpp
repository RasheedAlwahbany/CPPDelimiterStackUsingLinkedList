#include <iostream>
#include <string>
using namespace std;
class node{
	public:
		char info;
		node* next;
		node(){
			next=0;
		}
		node( char data,node* n){
			info=data;
			next=n;
			
		}		
};
class DILM{
	private:
		node* head;
		public:
		DILM(){
			head=0;
		}
		bool isempty(){
			return head==0;
		}

			void clear(){
			node* tmp;
			while(!isempty()){
			tmp=head;
			head=head->next;
			delete tmp;
			tmp=0;	
			}
			cout<<"The node cleared seccessfully."<<endl;
			//tail=0;			
		}
		~DILM(){
			clear();
			
		}
		node* First(){
			node* first;
			if(!isempty()){
				first=head;
				cout<<"The first data is :  "<<first->info<<endl;
				return first;
			}
			else{
				cout<<"The first number is not found."<<endl;
			return first;
		}
		}
		bool addtohead(char data){
			if(!isempty()){
			node* tmp=head;
			head=new node(data,head);
			head->next=tmp;
			return true;
		}
		else {
			head=new node(data,0);
			//cout<<"The item add seccessfully."<<endl;
			return true;
		}
	}
	void deletefromhead(){
			if(!isempty()){
			node* tmp;
			tmp=head;
			head=tmp->next;	
			delete tmp;
			tmp=0;	
		}
		
	}
	void check(){
		if(!isempty())
	{
		cout<<"\n\t\tFailed.\n\t\tThe paragraph is not corrects.\n\n\t\t\t-.-\n"<<endl;
	
	}
		else{
			cout<<"\n\t\tThe Dilimeter_stack list is empty.\n\t\t\tThe paragaraph is corrects %100.\n\t\t\t\t0_0\n"<<endl;
			
	}

	}
	
		bool pop(int item){
		if(!isempty())
	{
	
			if(head->info=='('&&item==')'){
			deletefromhead();	
			return true;
			}
			else if(head->info=='['&&item==']'){
			deletefromhead();			
			return true;
			}
			if(head->info=='{'&&item=='}'){
			deletefromhead();
			return true;
			}
			if(head->info=='/'&&item=='/'){
			deletefromhead();	
			return true;
			}
			else{	
			return 0;
			}
		}
		else{
				return 0;	
		}	
	}
	void push(char arr[],int count){
		char num1;
	for(int i=0;i<count;i++){
	if(arr[i]=='('||arr[i]=='['||arr[i]=='{'||arr[i]=='/'){
	if(arr[i]=='/'&&arr[i+1]=='*'){
	addtohead(arr[i]);
	}
	else if(arr[i]=='/'&&arr[i+1]!='*')
	continue;
	else
	addtohead(arr[i]);
	if(addtohead(arr[i])){
		cout<<"The item add seccessfully."<<endl;
	}
	}
	else if(arr[i]==')'||arr[i]=='}'||arr[i]==']'||arr[i]=='*'){
		num1=arr[i];
		if(arr[i]=='*'&&arr[i+1]=='/'){
			num1=arr[i+1];
		pop(num1);
		if(pop(num1)){
			cout<<"\nPop seccessuffully.\n"<<endl;
			continue;
		}
		else
		{
		cout<<"\nFailed.\n\t\tThis is paragraph is not corrects.\n"<<endl;
		addtohead('0');
		break;
		}	
	}
	else if(arr[i]=='*'&&arr[i+1]!='/'){
	continue;
	}
	else{
	pop(num1);
		if(pop(num1)){
		cout<<"\nPop seccessuffully.\n"<<endl;		
			continue;
		}
		else
		{
		cout<<"\nFailed.\n\t\tThis is paragraph is not corrects.\n"<<endl;
		addtohead('0');
		break;
		}
	}
	}
	if(arr[i]==';'){
	break;	
	}	
	}	
	}
};
int main(){
	DILM get; 
	int choose,count=-1;
	while(true){
	cout<<"Please choose the truth choice from bellow:\n1) Enter the string.\n2) Check.\n3) Clear."<<endl;
	cin>>choose;
	if(choose==1){
	cout<<"Please enter your string :"<<endl;
	char *arr=new char[256];
	for(int i=0;;i++){
	cin>>arr[i];
	++count;
	if(arr[i]==';'){
	get.push(arr,count);
	cout<<count<<endl;
	break;	
	}
	}
	}
	else if(choose==2){
		get.check();
	}
	else if(choose==3){
		get.clear();
	}
}
	system("pause");
	return 0;
}
