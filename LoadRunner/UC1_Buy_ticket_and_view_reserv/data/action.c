Action()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(30);

	lr_start_transaction("UC1_Buy_and_cancel");

	lr_start_transaction("1_login");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=129613.057837181zzzzQHVpzzcftAAAVpicQQHf", ENDITEM, 
		"Name=username", "Value=nina", ENDITEM, 
		"Name=password", "Value=dvde", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=63", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("1_login",LR_AUTO);

	lr_think_time(22);

	lr_start_transaction("2_click_flights");

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t4.inf", 
		LAST);

	lr_end_transaction("2_click_flights",LR_AUTO);

	lr_think_time(34);

	lr_start_transaction("3_choose_flight");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Frankfurt", ENDITEM, 
		"Name=departDate", "Value=09/15/2020", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=09/16/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("3_choose_flight",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("4_choose_time");

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=132;446;09/15/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=reserveFlights.x", "Value=28", ENDITEM, 
		"Name=reserveFlights.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("4_choose_time",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("5_fill_payment");

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=nina", ENDITEM, 
		"Name=lastName", "Value=nina", ENDITEM, 
		"Name=address1", "Value=gjglg", ENDITEM, 
		"Name=address2", "Value=gdys", ENDITEM, 
		"Name=pass1", "Value=nina nina", ENDITEM, 
		"Name=creditCard", "Value=47494033", ENDITEM, 
		"Name=expDate", "Value=04/23", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=outboundFlight", "Value=132;446;09/15/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=41", ENDITEM, 
		"Name=buyFlights.y", "Value=2", ENDITEM, 
		LAST);

	lr_end_transaction("5_fill_payment",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("5_click_itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("5_click_itinerary",LR_AUTO);

	lr_think_time(26);

	lr_start_transaction("6_cancel_reserv");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=205704540-815-nn", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=flightID", "Value=205704540-1584-nn", ENDITEM, 
		"Name=flightID", "Value=205704540-2353-nn", ENDITEM, 
		"Name=flightID", "Value=205704540-3123-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-3892-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-4661-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-5430-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-6200-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-6969-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-7738-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-8507-nn", ENDITEM, 
		"Name=flightID", "Value=168741577-9276-nn", ENDITEM, 
		"Name=flightID", "Value=149375275-10034-nn", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=57", ENDITEM, 
		"Name=removeFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("6_cancel_reserv",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("7_logout");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("7_logout",LR_AUTO);

	lr_end_transaction("UC1_Buy_and_cancel",LR_AUTO);

	return 0;
}