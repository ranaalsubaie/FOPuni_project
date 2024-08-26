#include <iostream>
#include <string>
#include<fstream>
using namespace std;

struct Apartment 
{
     string apartmentID;
      int price = 1000;
     int number_of_rooms;
     string status = "Available";  // Added status field and initialized to "Available" // to make evrey appartment Available until it is reserved  
};

struct Booking
 {
    Apartment apartment;
    string name;
    string mobile_number;
    string id;
    string status ;
    int duration; 
};

Apartment apartmentlist[100];
Booking bookinglist[100];

void addApartment(int& count) 
{
    bool flag = false;
    string checkdupliceted; 
    cout << "\n=====Add an apartment to the list=====\n";
    cout << "Enter Apartment name as an ID: ";
    cin >> checkdupliceted;

    for (int i = 0; i < count; i++)
     { 
        if (checkdupliceted == apartmentlist[i].apartmentID) 
        {
            flag = true;
            break;
        }
    }

    if (flag == true) 
    {
        cout << "Another apartment ID must be chosen; this one is already taken !\n";
    } 
    else
     {
        apartmentlist[count].apartmentID = checkdupliceted;
        cout << "Enter number of rooms: ";
        cin >> apartmentlist[count].number_of_rooms;
        

        cout << "Price per day: " << apartmentlist[count].price <<" SAR "<< endl;  
        count++; // Increment count to keep track of the number of apartments
    }
}

void showbookinglist(int& c )
{
   
        cout << "=======Booking list information=======\n";
        for (int i = 0; i < c; i++) 
        {
            
              
            cout << "Client Name: " << bookinglist[i].name << endl;
            cout<<"Clinet ID:"<<bookinglist[i].id<<endl;
            cout<<"Moblie number: "<<bookinglist[i].mobile_number<<endl;
            cout << "Apartment ID: " << bookinglist[i].apartment.apartmentID << endl;
            cout << "Room: " << bookinglist[i].apartment.number_of_rooms  << endl;
            //cout << "Room: " << apartmentlist[i].number_of_rooms  << endl;
          // cout << "Room: " << bookinglist[i].apartment.number_of_rooms << endl;
            
            cout << "Duration: " << bookinglist[i].duration << " days" << endl;
            cout << "Status: " << bookinglist[i].status << endl;
            cout << "=====================================\n";
              
        }
     
    
}


 void bookApartment(int& countappart, int& count) 
  {
    string id;
    bool find = false; // check if the id is not duplicated in bookinglist
    bool found = false;  // check if the entered apartment is available to book 
    cout << "\n=====Book an apartment=====\n";
    cout << "Enter the apartment ID you want to reserve: ";
    cin >> id;
    for(int i = 0 ; i <countappart ; i++ )
    {
        if(id == apartmentlist[i].apartmentID)
        found =true ; 
    }
    for (int i = 0; i < countappart; i++) 
    {
        if (id == apartmentlist[i].apartmentID&& apartmentlist[i].status!="Reserved") 
        {
            find = true;
            break;
        }
    }
  
 
    if (found==true) 
    {
        if(find==true&&found==true)
        {
            // Update apartment status to reserved //a sign client to number rooms 
            for (int i = 0; i < countappart; i++) 
            {
                if (id == apartmentlist[i].apartmentID) 
                {
                    apartmentlist[i].status = "Reserved";
                    bookinglist[count].apartment.number_of_rooms = apartmentlist[i].number_of_rooms;
                    

                    break; //once found and assigned breaks and go to gather the rest clinet info //
                }
                
            }

            // client information
            cout << "Enter your name: ";
            cin >> bookinglist[count].name;
            cout << "Enter your national ID: ";
            cin >> bookinglist[count].id;
            cout << "Enter your mobile number: ";
            cin >> bookinglist[count].mobile_number;
            cout << "Enter duration in days: ";
            cin >> bookinglist[count].duration;

            // Update booking status for booking
            bookinglist[count].status = "Reserved";
             
           //copying the appartment id to the index in booking apartmentid
            bookinglist[count].apartment.apartmentID = id;
            cout << "Apartment " << bookinglist[count].apartment.apartmentID << " has been successfully booked." << endl;
           
         count++; // Increment count to keep track of the number of client//
        } 
        else 
        {
            cout << "This room is reserved. Please check our available apartment list!\n";
        }
    }
   else
   {
       cout<<"Room is not found in the list , please add it \n";
   }
     
    
  
}

 
void displaybookinfo(int count)
{
       //function that display cilent info when it is called
        cout<<"\n =======Clinet information======\n ";
        cout << "Client Name: " << bookinglist[count].name << endl;
        cout << "Apartment ID: " << bookinglist[count].apartment.apartmentID << endl;
        cout << "Room: " << bookinglist[count].apartment.number_of_rooms  << endl;
         //cout << "Room: " << apartmentlist[i].number_of_rooms  << endl;
        // cout << "Room: " << bookinglist[i].apartment.number_of_rooms << endl;
        
        cout << "Duration: " << bookinglist[count].duration << " days" << endl;
        cout << "Status: " << bookinglist[count].status << endl;
        cout << "=====================================\n"; 
    
        
}
void showApartmentList(int count)
{
    //function that shows the record of all cilent we have//
  
    cout << "\n=======Apartment List=======\n";
    for (int i = 0; i < count; ++i) 
    {
        cout << "Apartment number: " << i + 1 << endl;
        cout << "Apartment ID: " << apartmentlist[i].apartmentID << endl; 
        cout << "Status: " << apartmentlist[i].status << endl;
        cout<<"Price per day:"<<apartmentlist[count].price <<" SAR "<<endl;
        cout << "============================\n";
    }
}

void cancelReservation(int& count) 
{  int index;
    
 string idToCancel;
    
 cout << "\n=====Cancel a reservation=====\n";
    
 cout << "Enter your ID to cancel reservation : ";
 
 cin >> idToCancel;

    bool flag =false ;
 for (int i = 0; i < count; i++)
 {
     if (bookinglist[i].id == idToCancel && bookinglist[i].status == "Reserved")
     {
         index=i ;
         flag=true ;
         break;
         
     }
 }
     
     if(flag==true)//once id found we change the status directly 
     {
        bookinglist[index].status = "Canceled";
        displaybookinfo(index) ;
        apartmentlist[index].status ="Available";
  
       cout << "Reservation with ID " << idToCancel << " has been canceled.\n";
   
     }
    
    
    else
     {
         cout << "No reservation found with ID " << idToCancel << " or it is already canceled.\n";
     }

}
void searchforanapartment(int search) //search for an apartment by apartment ID
{

    string searchID;
    bool found = false;

    cout << "\n=====Search for an apartment=====\n";
    cout << "Enter the ID of the apartment: ";
    cin >> searchID;

    for (int i = 0; i < search; i++) 
    {
        if (apartmentlist[i].apartmentID == searchID) 
        {
            cout << "Apartment found!" << endl;
            cout << "Apartment ID: " << apartmentlist[i].apartmentID << endl;
            cout << "Number of rooms: " << apartmentlist[i].number_of_rooms << endl;
            cout << "Status: " << apartmentlist[i].status << endl;
            found = true;
            break;

        }
    }

    if (!found)
    {
        cout << "Apartment not found." << endl;
    }
}
void save_booking_list(int &c)
{
    // function  saves the data into a file 
    ofstream filebooking;
	filebooking.open("booking.txt");
	if(!filebooking.is_open())
	{
		 cout<<"Problem with saving Booking list in Files \n";
		return ; 
	}
	int i=0;
	do
	{
		filebooking<<"=======Booking list information=======\n";
		filebooking<<"Client Name: " << bookinglist[i].name << endl;
		filebooking<< "Apartment ID: " << bookinglist[i].apartment.apartmentID << endl;
		filebooking<< "Room: " << bookinglist[i].apartment.number_of_rooms  << endl;
		filebooking<< "Duration: " << bookinglist[i].duration << " days" << endl;
		filebooking<< "Status: " << bookinglist[i].status << endl;
		filebooking<< "=====================================\n";
		i++;
	}while(i<c);
	filebooking.close();
    cout<<"Bookinglist information successfully saved in file \n";
    
    
     
}

void read_file(int & c)

{
    //function reads the data from a file and output the input in the terminal

	
    ifstream input("booking.txt");
    if (!input.is_open()) {
        cout << "Error: Unable to open the file booking.txt '\n";
        return;
    }

    string line;
    while (getline(input, line)) {
        cout << line << endl; 
    }

    input.close();
    cout << "File successfully uploaded to the program.\n";
}
void updateBooking(int & count ) 
{
 //function that will take an id as string and update the information of the client //

     string idtoupdate;
     cout << "\n=====Update a booking=====\n";
     cout << "Enter the ID of the Apartment to update your booking : ";
     cin >> idtoupdate;

     for (int i = 0; i < count; ++i)
     {
         if ( bookinglist[i].apartment.apartmentID == idtoupdate && bookinglist[i].status == "Reserved")
         {
             cout << "Booking found. Enter new details:\n";
             cout << "Enter your name: ";
             cin >> bookinglist[i].name;
             cout << "Enter your mobile number: ";
             cin >> bookinglist[i].mobile_number;
             cout << "Enter updated duration in days: ";
             cin >> bookinglist[i].duration;
             cout<<"\n";
             cout << "Booking details updated successfully.\n";
             return;
         }
     }
 
 cout<<" \n";

 cout << "No booking found with ID " << idtoupdate << " .\n";

}



  void deleteBooking(int& count , int countapp) 
{
    // Function to delete a client's booking from the booking record.
    
    string idToDelete;
    cout << "\n=====Delete a reservation=====\n";
    cout << "Enter your ID to delete your booking: ";
    cin >> idToDelete;

    bool found = false;

    for (int i = 0; i < count; ++i) 
    {
     
        if (bookinglist[i].id == idToDelete && bookinglist[i].status == "Reserved") 
        {
            // Update apartment status to "Available"
            for (int j = 0; j < countapp ; ++j) 
            {
                if (apartmentlist[j].apartmentID == bookinglist[i].apartment.apartmentID) 
                {
                    apartmentlist[j].status = "Available";
                    break;
                }
            }

            // delete the reservation from bookinglist //
            bookinglist[i] = bookinglist[count - 1];
            count--; // Decrease count since we removed a booking
            cout << "Reservation with ID " << idToDelete << " has been deleted.\n";
            found = true;
            break;
        }
    }


    if (!found) 
    {
        cout << "No reservation found with ID " << idToDelete << ", or it is already canceled!\n";
    }
}




int main() 
{
    int countApartment = 0;//sending it is adress so when it comes back the changes happen ; 
    int countClient = 0;//sending it is adress so when it comes back the changes happen ; 
    int choice;

    do {
        cout<<endl;
      cout << "    ******************************|Hotel Apartment|*****************************\n";
      cout << "    *          Enter 1->Add an Apartment to the System                         *\n";
      cout << "    *          Enter 2->Show Available/Reserved Apartments                     *\n";
      cout << "    *          Enter 3->Show Bookinglist                                       *\n";
      cout << "    *          Enter 4->Book an Apartment                                      *\n";
      cout << "    *          Enter 5->Cancel Booking                                         *\n";
      cout << "    *          Enter 6->Search for an Apartment                                *\n";
      cout << "    *          Enter 7->Update/Delete Booking information                      *\n";
      cout << "    *          Enter 8->Save Bookinglist and Read Apartmentlist from file      *\n";
      cout << "    *          Enter 9->Exit                                                   *\n";
       cout << "   ****************************************************************************\n";

       cout<<"        | Enter your Choice | :";
       cin >> choice;

       cout<<endl;


        switch (choice)
         {
            case 1: {
                addApartment(countApartment);
                break;
            }
            case 2: 
            {

                 showApartmentList(countApartment);
                break;
            }
            case 3: 
            {
              showbookinglist(countClient);
                break;
            }
            case 4: {
                bookApartment(countApartment, countClient); 
                break;
            }
            case 5: {
                cancelReservation(countClient);
                break;
            }
            case 6: {
                searchforanapartment(countApartment);
                break;
            }
            case 7 :
            {
                int numchoice ;
                cout<<"1. Update Booking Information \n";
                cout<<"2. Delete Booking Information \n";
                cout<<"Choice:";
                cin>>numchoice ;
                if(numchoice==1)
                {
                    updateBooking(countClient );
                }
             else if(numchoice==2)
                {
                   deleteBooking(countClient ,countApartment) ; 

                }
                else
                {
                    cout<<"Please select one of the choices above  ! \n" ;
                }
                break;
            }
            case 8: 
			{
                int c; 
                cout<<"1.Save Informaion in a File\n";
                cout<<"2.Read information in a File \n ";
                cout<<"Choice:";
                 cin>>c;

                if(c==1)

                { 
                   save_booking_list(countClient);
                }
                else if(c==2)
                {
                    read_file(countApartment);
                }
                else
               {
                   cout<<"Please select one of the choices above  ! \n" ;
               }
                break;
            }
			case 9:
			{
                cout<<"Thank you for using our Apartment system , see you next time ! \n";
				break;
				
			}
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice !=9);

    return 0;
}



