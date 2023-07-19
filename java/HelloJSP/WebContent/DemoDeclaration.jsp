<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="foo.*" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Demo Declaration JSP tag</title>
</head>
<body>
 Counter class count value: <%=Counter.getCount()  %>
 <br/>
 <%! int instancecount=0; %>
 Instance count value: <%= ++instancecount %>
 <br/>
 <%= Math.random()*50 %> 
 
 <%!
    public int doubleCount()
    {
	 instancecount *=2;
	 return instancecount;
    }
 %>

<% out.print("After doubleCount: "+doubleCount()); %> 
</body>
</html>