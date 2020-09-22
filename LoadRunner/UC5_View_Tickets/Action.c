Action()
{lr_start_transaction("UC5_View_Tickets");

	lr_start_transaction("goToSite");


///*Correlation comment: Automatic rules - Do not change!  
//Original value='129612.825354394zzzzQfQpHAtVzzzHtAAAVpHficcf' 
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
		"Name=login.x", "Value=51", ENDITEM,
		"Name=login.y", "Value=12", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click itinerary");

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
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC5_View_Tickets",LR_AUTO);

	return 0;
}