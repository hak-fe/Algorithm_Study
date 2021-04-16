import java.util.Scanner;

class User_information {
	String name;

	public User_information() {
		name = "";
	}

	public User_information(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
}

public class reservation {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int menuNum, seatClassNum, seatNum;
		String reservater;
		User_information[][] userInfo = new User_information[3][10];
		Scanner scanner = new Scanner(System.in);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				userInfo[i][j] = new User_information("--- ");
			}
		}
		System.out.println("��ǰ�ܼ�ƮȦ ���� �ý����Դϴ�.");
		while (true) {
			boolean isSame = false;
			System.out.print("����:1, ��ȸ:2, ���:3, ������:4>>");
			menuNum = scanner.nextInt();
			if (menuNum == 1) {
				System.out.print("�¼����� S(1), A(2), B(3)>>");
				seatClassNum = scanner.nextInt();
				if (seatClassNum == 1) {
					System.out.print("S>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("�̹� �ִ� �̸��Դϴ�. ó������ ���ư��ϴ�.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("��ȣ>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else if (seatClassNum == 2) {
					System.out.print("A>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("�̹� �ִ� �̸��Դϴ�. ó������ ���ư��ϴ�.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("��ȣ>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else if (seatClassNum == 3) {
					System.out.print("B>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("�̹� �ִ� �̸��Դϴ�. ó������ ���ư��ϴ�.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("��ȣ>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else {
					System.out.println("�¼���ȣ �Է��� �ùٸ��� �ʽ��ϴ�.");
				}
			} else if (menuNum == 2) {
				for (int i = 0; i < 3; i++) {
					if (i == 0)
						System.out.print("S>> ");
					else if (i == 1) {
						System.out.print("A>> ");
					} else
						System.out.print("B>> ");
					for (int j = 0; j < 10; j++) {
						System.out.print(userInfo[i][j].getName());
					}
					if (i < 2)
						System.out.println();
				}
				System.out.println();
				System.out.println("<<<��ȸ�� �Ϸ��Ͽ����ϴ�.>>>");
			} else if (menuNum == 3) {
				System.out.print("�¼� S:1, A:2, B:3>>");
				seatClassNum = scanner.nextInt();
				if (seatClassNum == 1) {
					System.out.print("S>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("���� �̸��Դϴ�.");
				} else if (seatClassNum == 2) {
					System.out.print("A>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("���� �̸��Դϴ�.");
				} else if (seatClassNum == 3) {
					System.out.print("B>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("�̸�>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("���� �̸��Դϴ�.");
				} else
					System.out.println("�¼���ȣ �Է��� �ùٸ��� �ʽ��ϴ�.");
			} else if (menuNum == 4) {
				break;
			} else {
				System.out.println("�޴� �Է� ��ȣ�� �߸��Ǿ����ϴ�.");
			}
		}
		scanner.close();
	}
}