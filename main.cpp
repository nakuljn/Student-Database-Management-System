#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{


    cout<<"Choose Options\n1. Student Login\n2. Admin Login\n3. Instructor Login\n4. Exit\n";
    int n = 0;
    cin>>n;

    while(n != 4){

    	while(n==1)
		{
    		string rollno;
    		cout<<"Choose Options\n1. View Record\n2. Exit\n";
			int v;
    		cin>>v;
    		if(v==1)
	    	{
	    		cout<<"Enter Roll no.: ";
		        cin>>rollno;
		        string heads[7]={"Roll No.: ","Name: ","CGPA: ","Course1: ","Course2: ","Course3: ","Course4: "};
		        ifstream infile;
		        infile.open("record1.txt");
		        string line;
		        int flag=0;
		        while (getline(infile, line)) {
		            istringstream words(line);
		            string word;
		            words>>word;
		            if(word==rollno){
		                flag=1;
		                system("cls");
		                istringstream details(line);
		                string value;
		                int headsc=0;
		                while(details>>value){
		                    cout<<heads[headsc++]<<value<<endl;
		                }
		                break;
		            }
		        }
		        if(flag==0)
				{
		            cout<<"No record found!"<<endl;
		        }
		        infile.close();
			}
	        if(v==2)
	        {
	        	break;
			}
	    }
        while(n==2){
    		string aduser = "abcd";
		  	string adpass = "efgh";
    		cout<<"1. Login\n2. Exit\n";
            int x;
            cin>>x;
            if(x==1)
            {
            	string user,pass;
                cout<<"Enter Login Id\n";
                cin>>user;
                cout<<endl<<"Password :";
		 	    cin>>pass;
		 	    if(user!=aduser || pass!=adpass)
				{
		    		cout<<endl<<"invalid credentials"<<endl;
				}
				if(user==aduser && pass==adpass)
				{
					cout<<"Login Successful"<<endl;
        			cout<<"Choose Options\n1. View Student Records\n2. Add Student Record\n3. Delete Student Record\n4. Exit"<<endl;

        			while(1)
        			{
        				int a = 0;
        				cin>>a;

        				if(a == 1){
                            fstream fin;
                            fin.open("record1.txt");
                            fin.seekg(0, ios::end);
                            if(fin.tellg() == 0)
                                 cout<<"No records found"<<endl;
                            else{
                                 string line;
                                 fin.seekg(0, ios::beg);
                                 while(fin){
                                    getline(fin, line);
                                    cout<<line<<endl;
                                }
                            }

        				}
        				if(a==2)
		                   {
		                      string roll;
		                      string name;
		                      string cgpa;
		                      string c1;
		                      string c2;
		                      string c3;
		                      string c4;
		                      cout<<"Enter roll no. :";
		                      cin>>roll;
		                      cout<<endl<<"Enter name :";
		                      cin>>name;
		                      cout<<endl<<"Enter cgpa :";
		                      cin>>cgpa;
		                      cout<<endl<<"Enter grade in course 1 :";
		                      cin>>c1;
		                      cout<<endl<<"Enter grade in course 2 :";
		                      cin>>c2;
		                      cout<<endl<<"Enter grade in course 3 :";
		                      cin>>c3;
		                      cout<<endl<<"Enter grade in course 4 :";
		                      cin>>c4;
		                      cout<<endl<<"Record added Successfully";

		                      string append;
		                      append=roll+" "+name+" "+cgpa+" "+c1+" "+c2+" "+c3+" "+c4;
		                      ofstream fout;
		                      fout.open("record1.txt",ios::app);
		                      fout<<append<<endl;
		                      fout.close();

		            		}
		            	if(a==3)
		            	{
		            		cout<<"Enter Roll No. of the record to delete"<<endl;
		            		string roll_no;
		            		string word;
		            		cin>>roll_no;
		            		ifstream fin;
							fin.open("record1.txt");
							int flag = 0;
							ofstream temp;
							temp.open("temp.txt");
							while (fin>>word)
							{
                                if(word==roll_no)
								{  flag = 1;
                                    string deletelinetemp;
									string line;
									getline(fin,deletelinetemp);
									string deleteline = word + deletelinetemp;
									ifstream fin2;
									fin2.open("record1.txt");
									while(getline(fin2,line))
									{
									    if(line!=deleteline)
                                        {
                                                temp << line << endl;
                                        }
									}
									temp.close();
									fin.close();
									fin2.close();
									remove("record1.txt");
									rename("temp.txt","record1.txt");
									cout<<"Recorded deleted successfully"<<endl;
									break;
								}
							}
							if(flag == 0)
                                cout<<"No such record found"<<endl;
		            	}
		            	if(a==4)
		            	{
		            		break;
		            	}
		            	cout<<"\nChoose Options\n1. View Student Records\n2. Add Student Record\n3. Delete Student Record\n4. Exit"<<endl;
        			}
				}
            }
            if(x==2)
            {
            	break;
            }
         }

        while(n == 3){
            cout<<"1. Login\n2. Sign Up\n3. Exit\n";
            int x;
            cin>>x;
            if(x==1){
                fstream file;
                file.open("record2.txt", ios::in | ios::out);
                cout<<"Enter Username\n";
                string username;
                cin>>username;
                string password;
                cout<<"Enter Password"<<endl;
                cin>>password;
                string word;
                int flag1 = 0;
                int flag2 = 0;
                while(file >> word){
                    if(username == word){
                            flag1 = 1;
                    }
                    if(flag1){
                        file >> word;
                        if(password == word){
                            flag2 = 1;
                        }
                    }
                    if(flag1 && flag2)
                        break;
                }
                file.close();

                if(flag1 && flag2){
                    cout<<"Welcome"<<endl;
                    while(1){
                        cout<<"What you want to do"<<endl;
                        cout<<"1. View Records of a student\n2. Edit grades of a student\n3. Exit"<<endl;
                        int op;
                        cin>>op;
                        if(op == 1){
                                fstream record;
                                record.open("record1.txt", ios::in | ios::out);
                                cout<<"Enter Roll Number"<<endl;
                                string roll;
                                cin >> roll;
                                string word2;
                                int flag3 = 0;
                                while(record >> word2){
                                    if(word2 == roll){
                                        flag3 = 1;
                                        string temp;
                                        getline(record, temp);
                                        string str = roll + " " +temp;
                                        cout<<str<<endl;
                                        break;
                                    }
                                }
                                if(flag3 == 0)
                                    cout<<"Record not Found"<<endl;

                                record.close();

                            }
                        if(op == 2){
                                fstream record;
                                record.open("record1.txt", ios::in | ios::out);
                                cout<<"Enter Roll Number"<<endl;
                                string roll;
                                cin >> roll;
                                string word2;
                                int flag4 = 0;
                                fstream temp;
                                temp.open("tempfile.txt", ios::out);
                                int count = 0;
                                while(record >> word2){
                                    count++;
                                    if(roll == word2){
                                        flag4 = 1;
                                        string rolltemp, nametemp, cgpatemp, c1temp, c2temp, c3temp, c4temp;
                                        string strfin;
                                         cout<<"enter grade in course1"<<endl;
                                         cin>>c1temp;
                                         cout<<"enter grade in course2"<<endl;
                                         cin>>c2temp;
                                         cout<<"enter grade in course3"<<endl;
                                         cin>>c3temp;
                                         cout<<"enter grade in course4"<<endl;
                                         cin>>c4temp;

                                        rolltemp = roll;
                                        record >> word2;
                                        nametemp = word2;
                                        record >> word2;
                                        cgpatemp = word2;
                                        record >> word2;
                                        record >> word2;
                                        record >> word2;
                                        record >> word2;
                                        record >> word2;
                                        strfin = rolltemp+" "+nametemp+" "+cgpatemp+" "+c1temp+" "+c2temp+" "+c3temp+" "+c4temp;
                                        temp << strfin <<endl;
                                    }

                                    temp << word2 <<" ";
                                    if(count%7 == 0){
                                        temp << endl;
                                        count = 0;
                                    }
                                }
                                temp.close();
                                record.close();
                                remove("record1.txt");
                                rename("tempfile.txt", "record1.txt");
                                if(flag4 == 0){
                                    cout<<"No such roll number found"<<endl;

                                }
                            }

                        if(op == 3){
                                break;
                            }
                        }
                    }
                    else{
                        cout<<"Invalid Credentials"<<endl;
                    }
                }

                if(x==2){
                    ofstream file;
                    file.open("record2.txt", ios::out | ios::app);
                    cout<<"Enter Username"<<endl;
                    string username;
                    cin>>username;
                    cout<<"Enter Password"<<endl;
                    string password;
                    cin>>password;
                    cout<<"Enter your course number"<<endl;
                    string course;
                    cin>>course;
                    string str = username + " " + password + " " + course;
                    file<<str<<endl;
                    file.close();
                }

                if(x==3)
                    break;
            }
        cout<<"Choose Options\n1. Student Login\n2. Admin Login\n3. Instructor Login\n4. Exit\n";
        cin>>n;
    }
}
