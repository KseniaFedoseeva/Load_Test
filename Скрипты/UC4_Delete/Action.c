Action()
	
	{
	int flight_id_num = 0;
	
	lr_start_transaction("UC4_Cancel_reserv");
lr_start_transaction("goToSite");

/*Correlation comment: Automatic rules - Do not change!  
Original value='129627.766059133zzzHHcipcVzzzzzHtAAAzpDzQD' 
Name ='userSession' 
Type ='Rule' 
AppName ='WebTours' 
RuleName ='userSession'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"RequestUrl=*/nav.pl*",
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
		"Name=login.x", "Value=67", ENDITEM,
		"Name=login.y", "Value=13", ENDITEM,
		LAST);
lr_end_transaction("login",LR_AUTO);
lr_start_transaction("click_itinerary");
	
	web_reg_save_param("fl_id",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);

	web_reg_find("Text=Itinerary",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
flight_id_num = atoi(lr_eval_string("{flightID_count}"));
                     
                     
lr_end_transaction("click_itinerary",LR_AUTO);

	lr_think_time(7);

	lr_start_transaction("Cancel");
	
	web_reg_save_param("fl_id",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);

	
	web_reg_find("Fail=NotFound",
		"Text=A total of",
		LAST);

	

	web_submit_form("web_submit_form",
		ITEMDATA, "Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=67", ENDITEM,
		"Name=removeFlights.y", "Value=12", ENDITEM, 
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", "Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		ENDITEM,
		LAST);
	
	if(atoi(lr_eval_string("{flightID_count}")) < flight_id_num){ 
		lr_output_message("itinerary deleted successfull");

	} else lr_error_message("itinerary not deleted");

	
//	web_submit_data("itinerary.pl", 
//		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
//		"Method=POST", 
//		"TargetFrame=", 
//		"RecContentType=text/html", 
//		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
//		"Snapshot=t4.inf", 
//		"Mode=HTML", 
//		ITEMDATA, 
//		"Name=1", "Value=on", ENDITEM, 
//		"Name=flightID", "Value=205704540-815-nn", ENDITEM, 
//		"Name=flightID", "Value=205704540-1584-nn", ENDITEM, 
//		"Name=flightID", "Value=205704540-2353-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-3123-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-3892-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-4661-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-5430-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-6200-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-6969-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-7738-nn", ENDITEM, 
//		"Name=flightID", "Value=168741577-8507-nn", ENDITEM, 
//		"Name=flightID", "Value=149375275-9265-nn", ENDITEM, 
//		"Name=.cgifields", "Value=6", ENDITEM, 
//		"Name=.cgifields", "Value=11", ENDITEM, 
//		"Name=.cgifields", "Value=3", ENDITEM, 
//		"Name=.cgifields", "Value=7", ENDITEM, 
//		"Name=.cgifields", "Value=9", ENDITEM, 
//		"Name=.cgifields", "Value=12", ENDITEM, 
//		"Name=.cgifields", "Value=2", ENDITEM, 
//		"Name=.cgifields", "Value=8", ENDITEM, 
//		"Name=.cgifields", "Value=1", ENDITEM, 
//		"Name=.cgifields", "Value=4", ENDITEM, 
//		"Name=.cgifields", "Value=10", ENDITEM, 
//		"Name=.cgifields", "Value=5", ENDITEM, 
//		"Name=removeFlights.x", "Value=67", ENDITEM, 
//		"Name=removeFlights.y", "Value=12", ENDITEM, 
//		LAST);

	lr_end_transaction("Cancel",LR_AUTO);

	
web_reg_find("Text=To make reservations,please enter your account information to the left",
		LAST);
	
	lr_start_transaction("logout");
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC4_Cancel_reserv",LR_AUTO);

	return 0;
}