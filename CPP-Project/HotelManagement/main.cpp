// C++ program to solve
// the given question

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Creating class for hotelManagement data.
class HotelManage {
public:
	string hotelname;
	int availableroom;
	string place;
	int ratingofhotel;
	int priceperroom;
};

// Creating class for customer data.
class Customer : public HotelManage {
public:
	string customername;
	int customerid;
	int totalcost;
};

// Sorting the Hotels by Bangalore Location
bool sortByBangalore(HotelManage& A, HotelManage& B)
{
	return A.hotelname > B.hotelname;
}

// Sorting the hotels based on Ratings provided
bool sortByRating(HotelManage& A, HotelManage& B)
{
	return A.ratingofhotel > B.ratingofhotel;
}

//Sorting the Hotels based on the Availability of the Room
bool sortByRoomAvailability(HotelManage& A,
						HotelManage& B)
{
	return A.availableroom < B.availableroom;
}

//Displaying the Hotels data
void PrintHotelData(vector<HotelManage> hotels)
{
	cout << "----------DISPLAYING HOTELS DATA:------------------" << endl;
	cout<<endl;
	cout << "HOTEL"
		<< "\t"
		<< "ROOM AVAILABLILITY"
		<< "\t"
		<< "PLACE"
		<< "\t\t"
		<< "RATING"
		<< "\t"
		<< "PRICE PER ROOM:" << endl;
    cout<<endl;

	for (int i = 0; i < 3; i++) {
		cout << hotels[i].hotelname
			<< "\t\t"
			<< hotels[i].availableroom
			<< "\t\t"
			<< hotels[i].place
			//<< "	 "
			<<"\t"

			<< hotels[i].ratingofhotel
			//<< "		 "
			<<"\t"
			<< hotels[i].priceperroom
			<< endl;
	}
	cout << endl;
	cout<<endl;
}

// Sorting by name using HotelManagement data
void SortHotelByName(vector<HotelManage> hotels)
{
	cout << "-------------SORT BY NAME:-------------------------------" << endl;
	cout<<endl;

	std::sort(hotels.begin(), hotels.end(),
			sortByBangalore);

    cout << "HOTEL"
		<< "\t"
		<< "ROOM AVAILABLILITY"
		<< "\t"
		<< "PLACE"
		<< "\t\t"
		<< "RATING"
		<< "\t"
		<< "PRICE PER ROOM:" << endl;
    cout<<endl;

	for (int i = 0; i < hotels.size(); i++) {
		cout << hotels[i].hotelname << "\t\t"
			<< hotels[i].availableroom << "\t\t"
			<< hotels[i].place << "\t"
			<< hotels[i].ratingofhotel << "\t"
			<< " " << hotels[i].priceperroom
			<< endl;
	}
	cout << endl;
	cout<<endl;
}

// Sorting the Hotels By Rating
void SortHotelByRating(vector<HotelManage> hotels)
{
	cout << "------------------------SORT BY A RATING------------------------------:" << endl;
	cout<<endl;

	std::sort(hotels.begin(),
			hotels.end(), sortByRating);

    cout << "HOTEL"
		<< "\t"
		<< "ROOM AVAILABLILITY"
		<< "\t"
		<< "PLACE"
		<< "\t\t"
		<< "RATING"
		<< "\t"
		<< "PRICE PER ROOM:" << endl;
    cout<<endl;


	for (int i = 0; i < hotels.size(); i++) {
		cout << hotels[i].hotelname << " \t\t"
			<< hotels[i].availableroom << "\t\t"
			<< hotels[i].place<< "\t "
			<< hotels[i].ratingofhotel<< " \t\t"
			<< " " << hotels[i].priceperroom
			<< endl;
	}
	cout << endl;
	cout<<endl;
}

// Showing the hotel details for any city Location
void PrintHotelBycity(string s,
					vector<HotelManage> hotels)
{
	cout << "--------------------HOTELS IN " << s
		<< " LOCATION IS:------------------------------"
		<< endl;
    cout<<endl;

    cout << "HOTEL"
		<< "\t"
		<< "ROOM AVAILABLILITY"
		<< "\t"
		<< "PLACE"
		<< "\t\t"
		<< "RATING"
		<< "\t"
		<< "PRICE PER ROOM:" << endl;
    cout<<endl;

	for (int i = 0; i < hotels.size(); i++) {

		if (hotels[i].place== s) {

			cout << hotels[i].hotelname << "\t"
				<< hotels[i].availableroom << "\t\t\t"
				<< hotels[i].place << "\t "
				<< hotels[i].ratingofhotel << "\t"
				<< " " << hotels[i].priceperroom
				<< endl;
		}
	}
	cout << endl;
	cout<<endl;
}

// Sorting hotel based on Availability of the room
void SortByRoomAvailable(vector<HotelManage> hotels)
{
	cout << "----------------------------SORT BY ROOM AVAILABLE:-----------------------------------" << endl;
	cout<<endl;

	std::sort(hotels.begin(), hotels.end(),
			sortByRoomAvailability);

    cout << "HOTEL"
		<< "\t"
		<< "ROOM AVAILABLILITY"
		<< "\t"
		<< "PLACE"
		<< "\t\t"
		<< "RATING"
		<< "\t"
		<< "PRICE PER ROOM:" << endl;
    cout<<endl;

	for (int i = hotels.size() - 1; i >= 0; i--) {

		cout << hotels[i].hotelname << "\t"
			<< hotels[i].availableroom << "\t\t\t"
			<< hotels[i].place << "\t "
			<< hotels[i].ratingofhotel<< " \t"
			<< " " << hotels[i].priceperroom
			<< endl;
	}
	cout << endl;
	cout<<endl;
}

// Displaying Customer's data
void PrintUserData(string userName[],
				int userId[],
				int bookingCost[],
				vector<HotelManage> hotels)
{

	vector<Customer> user;
	Customer u;

	// Accessing data of Customer
	for (int i = 0; i < 3; i++) {
		u.customername = userName[i];
		u.customerid = userId[i];
		u.totalcost = bookingCost[i];
		user.push_back(u);
	}

	// Displaying Customer Data
	cout << "-----------------------------------DISPLAYING CUSTOMER BOOKING DATA:------------------------------------------------"
		<< endl;
    cout<<endl;

	cout << "CUSTOMERNAME"
		<< "\t"
		<< "CUSTOMERID"
		<< "\t"
		<< "HOTELNAME"
		<< "\t"
		<< "BOOKINGCOST" << endl;
    cout<<endl;

	for (int i = 0; i < user.size(); i++) {
		cout << user[i].customername
			<< "		 "
			<< user[i].customerid
			<< "\t\t"
			<< hotels[i].hotelname
			<< "		 "
			<< user[i].totalcost
			<< endl;
	}
}

// Functions used in Hotel Management Project
void HotelManagement(string userName[],
					int userId[],
					string hotelName[],
					int bookingCost[],
					int rooms[],
					string locations[],
					int ratings[],
					int prices[])
{
	// Initialize arrays that stores
	// hotel data and customer data
	vector<HotelManage> hotels;

	// Create Objects for
	// hotel and customer.
	HotelManage h;

	// Initialising the data
	for (int i = 0; i < 3; i++) {
		h.hotelname = hotelName[i];
		h.availableroom = rooms[i];
		h.place = locations[i];
		h.ratingofhotel = ratings[i];
		h.priceperroom = prices[i];
		hotels.push_back(h);
	}
	cout << endl;

	// Invoking the various operations
	PrintHotelData(hotels);
	SortHotelByName(hotels);
	SortHotelByRating(hotels);
	PrintHotelBycity("Bangalore",
					hotels);
	SortByRoomAvailable(hotels);
	PrintUserData(userName,
				userId,
				bookingCost,
				hotels);
}

// Driver Code.
int main()
{

	// Initialize variables to stores
	// hotels data and user data.
	string userName[] = { "Grace", "Juliet", "Jasmine" };
	int userId[] = { 201, 305, 414 };
	string hotelName[] = { "Heaven", "Empire", "TajKin" };
	int bookingCost[] = { 10000, 20000, 11500 };
	int rooms[] = { 4, 5, 6 };
	string locations[] = { "Bangalore",
						"Mangalore",
						"Bangalore" };
	int ratings[] = { 5, 4, 3 };
	int prices[] = { 100, 200, 300 };

	// Functions to perform  Hotel Management operations
	HotelManagement(userName, userId,
					hotelName, bookingCost,
					rooms, locations,
					ratings, prices);

	return 0;
}
