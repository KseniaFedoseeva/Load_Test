Action()
{lr_start_transaction("UC1_Buy_and_view");
	lr_start_transaction("goToSite");

	
	

///*Correlation comment: Automatic rules - Do not change!  
//Original value='129613.057837181zzzzQHVpzzcftAAAVpicQQHf' 
//Name ='userSession' 
//Type ='Rule' 
//AppName ='WebTours' 
//RuleName ='userSession'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"RequestUrl=*/nav.pl*",
//		LAST);
//		

web_reg_save_param("userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"/>",
		"NotFound=ERROR",
		LAST);
		
		web_reg_find("Text=Welcome to the Web Tours site",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_transaction("goToSite", LR_AUTO);


	lr_think_time(5);

	

	lr_start_transaction("login");
	
	web_reg_find("Text=Welcome",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=63", ENDITEM,
		"Name=login.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click_flights");
	
	web_reg_find("Text=Departure City",
		LAST);

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

	lr_end_transaction("click_flights",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("fill_find_flight");

/*Correlation comment: Automatic rules - Do not change!  
Original value='132;446;09/15/2020' 
Name ='outboundFlight' 
Type ='Rule' 
AppName ='WebTours' 
RuleName ='outboundFlight'*/
//	web_reg_save_param_attrib(
//		"ParamName=outboundFlight",
//		"TagName=input",
//		"Extract=value",
//		"Name=outboundFlight",
//		"Type=radio",
//		"Ordinal=ALL",
//		LAST);
//		
		
		web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		"Ordinal=ALL",
		LAST);

		
		
//		web_reg_save_param("outboundFlight",
//		"LB=name=\"outboundFlight\" value=\"",
//		"RB=\"",
//		"NotFound=ERROR",
//		LAST);
		
		web_reg_save_param("flight_id",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=;",
		"Ord=ALL",
		LAST);
		
		web_reg_save_param("flight_time",
		"LB=<td align=\"center\">",
		"RB=m<td align=\"center\">",
		"Ord=ALL",
		LAST);
		
	web_reg_find("Text=Flight departing from",
	LAST);
	
	web_reg_find("Text={seat}",
		LAST);

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
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={Arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seat}", ENDITEM, 
		"Name=seatType", "Value={type}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=51", ENDITEM, 
		"Name=findFlights.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("fill_find_flight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("choose_flight");
	
	web_reg_find("Text=Flight Reservation",
		LAST);
	
	web_reg_find("Text={type}",
		LAST);

	// lr_save_string(lr_eval_string("outboundFlight_{random_id}"), "outboundFlight_id");
	               
	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight_3}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={type}", ENDITEM,
		"Name=seatPref", "Value={seat}", ENDITEM,
		"Name=reserveFlights.x", "Value=28", ENDITEM,
		"Name=reserveFlights.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("fill_payment");
	
	web_reg_find("Text=Reservation Made!",
	LAST);
	
	web_reg_find("Text=from {depart} to {Arrive}",
		LAST);
	
	 web_reg_find("Text={departDate} :  {flight_time_3}m : Flight {flight_id_3} leaves {depart}  for {Arrive}", LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={login}", ENDITEM,
		"Name=lastName", "Value={login}", ENDITEM,
		"Name=address1", "Value={address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={login} {login}", ENDITEM,
		"Name=creditCard", "Value={credit}", ENDITEM,
		"Name=expDate", "Value={randomMonth}/{randomYear}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={type}", ENDITEM,
		"Name=seatPref", "Value={seat}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight_3}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=41", ENDITEM,
		"Name=buyFlights.y", "Value=2", ENDITEM,
		LAST);

	lr_end_transaction("fill_payment",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click itinerary");
	
	web_reg_find("Text=Itinerary",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click itinerary",LR_AUTO);

	lr_think_time(5);


	lr_start_transaction("logout");
	
	web_reg_find("Text=To make reservations,please enter your account information to the left",
		LAST);

web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC1_Buy_and_view",LR_AUTO);

	return 0;
}