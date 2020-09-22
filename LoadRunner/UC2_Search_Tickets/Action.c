Action()
{
	lr_start_transaction("UC2_Search_Tickets");
	lr_start_transaction("goToSite");


///*Correlation comment - Do not change!  Original value='129607.394572701zzzzziApDfiDDDDDtAAAApAicVf' Name ='userSession' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		"RequestUrl=*/nav.pl*",
//		LAST);
		
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

	web_reg_find("Fail=NotFound",
		"Text=User password was correct",
		LAST);
	
	web_reg_find("Text={login}",
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
		"Name=login.x", "Value=51", ENDITEM,
		"Name=login.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click_flights");

	web_reg_find("Text=Web Tours",
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


/*Correlation comment - Do not change!  Original value='001;0;09/14/2020' Name ='outboundFlight' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=outboundFlight",
//		"TagName=input",
//		"Extract=value",
//		"Name=outboundFlight",
//		"Type=radio",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		LAST);

	web_reg_save_param("outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"NotFound=ERROR",
		LAST);

web_reg_find("Text=Flight Selections",
	LAST);


	web_reg_find("Text=<B>{depart}</B> to <B>{Arrive}</B> on <B>{departDate}</B>",
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
		"Name=findFlights.x", "Value=40", ENDITEM,
		"Name=findFlights.y", "Value=13", ENDITEM,
		LAST);
		
		lr_end_transaction("fill_find_flight", LR_AUTO);


	

	lr_think_time(5);

	lr_start_transaction("choose_flight");

	web_reg_find("Text=Flight Reservation",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={type}", ENDITEM,
		"Name=seatPref", "Value={seat}", ENDITEM,
		"Name=reserveFlights.x", "Value=58", ENDITEM,
		"Name=reserveFlights.y", "Value=11", ENDITEM,
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("logout");

	web_reg_find("Text=Web Tours",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC2_Search_Tickets",LR_AUTO);

	return 0;
}