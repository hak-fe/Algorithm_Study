import java.util.Scanner;
public class ch2_10 {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		
		int x1, y1, r1; // �� ��° ���� �߽� ��ǥ�� �������� ���̸� ������ ����
		int x2, y2, r2; // �� ��° ���� �߽� ��ǥ�� �������� ���̸� ������ ����
		int DistanceOfPoint; // �߽ɰ� �߽� ������ �Ÿ��� ������ ����
		
		System.out.print("ù��° ���� �߽ɰ� ������ �Է�>>");
		x1 = scanner.nextInt();
		y1 = scanner.nextInt();
		r1 = scanner.nextInt();
		
		System.out.print("�ι�° ���� �߽ɰ� ������ �Է�>>");
		x2 = scanner.nextInt();
		y2 = scanner.nextInt();
		r2 = scanner.nextInt();
		
		DistanceOfPoint = (int)Math.sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		
		  if(r1 + r2 > DistanceOfPoint) 
			System.out.println("�� ���� ���� ��ģ��.");
		else
			System.out.println("�� ���� ���� ��ġġ �ʴ´�.");
		
		scanner.close();
	}

}
