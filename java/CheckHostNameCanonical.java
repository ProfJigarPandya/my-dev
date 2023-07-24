class		CheckDNS
{
	public static void main(String args[]) throws UnknownHostException
	{
		System.out.println("Hello Java");
		InetAddress	addr = InetAddress.getLocalHost();
				System.	out.	println(
				       		String.	format(
		       		"IP:%s hostname:%s canonicalName:%s",
			   		addr.		getHostAddress(),
			      		addr.		getHostName(),
		      		addr.		getCanonicalHostName()
							)
		);
	}
}
