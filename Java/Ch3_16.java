import java.util.Scanner;

public class Ch3_16 {

	public static void main(String[] args) {
		// TODO �ڵ� ������ �޼ҵ� ����
		Scanner s = new Scanner(System.in);
		System.out.println("��ǻ�Ϳ� ���� ���� �� ������ �մϴ�.");
		while (true) {
			System.out.print("���� ���� ��!>>");
			String myChoice = s.next(); // ����ڰ� ������ ��
			int n = (int) (Math.random() * 3);
			String str[] = { "����", "����", "��" };

			if (myChoice.compareTo("�׸�") == 0) { // ����ڰ� �׸��̶�� �Է��� ���
				System.out.println("������ �����մϴ� . . . .");
				break;
			}
			if (str[n].equals("����")) { // ��ǻ�Ͱ� �� ���� ������ ���
				if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", �����ϴ�.");

				else if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �̰���ϴ�.");

				else if (myChoice.equals("��"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �����ϴ�.");

			} else if (str[n].equals("����")) { // ��ǻ�Ͱ� �� ���� ������ ���
				if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �����ϴ�.");

				else if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", �����ϴ�.");

				else if (myChoice.equals("��"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �̰���ϴ�.");
			} else if (str[n].equals("��")) { // ��ǻ�Ͱ� �� ���� ���� ���
				if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �̰���ϴ�.");

				else if (myChoice.equals("����"))
					System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", ����ڰ� �����ϴ�.");
			} else if (myChoice.equals("��"))
				System.out.println("����� = " + myChoice + " , ��ǻ�� = " + str[n] + ", �����ϴ�.");
		}
	}
}
