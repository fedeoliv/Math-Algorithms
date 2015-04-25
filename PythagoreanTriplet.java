import java.util.*;

/* Given an array of integers, return true if there is a triplet (a, b, c) 
 * that satisfies a^2 + b^2 = c^2. */

class PythagoreanTriplet {
	private static boolean findTriplet(int[] input) {
		HashMap<Integer, Integer> hm = new HashMap<>();
		
		for (int i : input) hm.put(i * i, i);
		
		for (int i = 1; i < input.length; i++) {
			int square = input[i] * input[i] + input[i - 1] * input[i - 1];
			
			if (hm.get(square) != null) {
				System.out.println(input[i] + " " + input[i - 1] + " " + hm.get(square));
				//return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		int[] input = { 3, 1, 4, 6, 5 };
		Arrays.sort(input);
		System.out.println(findTriplet(input));
	}
}
