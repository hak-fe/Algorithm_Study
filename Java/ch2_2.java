import java.util.Scanner;

public class ch2_2 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("2자리수 정수 입력(10~99)>>");
		int input = scanner.nextInt();
		
		if (input < 10 || input > 99) {
			System.out.println("10이상 99이하의 수를 입력해주세요.");
		} 
		else {
			if (input / 10 == input % 10) {

				System.out.println("Yes! 10의 자리와 1의자리가 같습니다.");

			} else {

				System.out.println("No! 10의 자리와 1의자리가 같지 않습니다.");
			}
		}
	}

}