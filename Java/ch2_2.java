import java.util.Scanner;

public class ch2_2 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.print("2�ڸ��� ���� �Է�(10~99)>>");
		int input = scanner.nextInt();
		
		if (input < 10 || input > 99) {
			System.out.println("10�̻� 99������ ���� �Է����ּ���.");
		} 
		else {
			if (input / 10 == input % 10) {

				System.out.println("Yes! 10�� �ڸ��� 1���ڸ��� �����ϴ�.");

			} else {

				System.out.println("No! 10�� �ڸ��� 1���ڸ��� ���� �ʽ��ϴ�.");
			}
		}
	}

}