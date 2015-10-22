import java.util.*;

public class EmailAliases {

	public static void main(String[] args) {
		Map<String,ArrayList<String>> count = new Hashtable<String,ArrayList<String>>();

		Scanner input = new Scanner(System.in);

		int noAdresses = input.nextInt();
		String throwaway = input.nextLine();
		for(int i = 0; i < noAdresses; ++i) {
			String address = input.nextLine();
			String addNorm = normalize(address);

			if(!count.containsKey(addNorm)) {
				count.put(addNorm,new ArrayList<String>());
			}
			count.get(addNorm).add(address);
		}

		System.out.println(count.entrySet().size());

		Iterator it = count.entrySet().iterator();

		while(it.hasNext()) {
			Map.Entry entry = (Map.Entry)it.next();
			ArrayList<String> ss = (ArrayList<String>)entry.getValue();
			System.out.print(ss.size());
			for(String s:ss) {
				System.out.print(" " + s);
			}
			System.out.println();
		}
	}

	private static String normalize(String str) {
		String norm = str.toLowerCase();
		String[] userAndDom = norm.split("@");
		String user = userAndDom[0];
		String domain = userAndDom[1];
		
		if(domain.equals("bmail.com")) {
			user = user.split("\\+")[0];
			user = user.replaceAll("\\.","");
			norm = user + "@" +domain;
		}
		
		return norm;
	}

}