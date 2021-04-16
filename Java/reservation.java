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
		System.out.println("명품콘서트홀 예약 시스템입니다.");
		while (true) {
			boolean isSame = false;
			System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4>>");
			menuNum = scanner.nextInt();
			if (menuNum == 1) {
				System.out.print("좌석구분 S(1), A(2), B(3)>>");
				seatClassNum = scanner.nextInt();
				if (seatClassNum == 1) {
					System.out.print("S>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("이미 있는 이름입니다. 처음으로 돌아갑니다.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("번호>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else if (seatClassNum == 2) {
					System.out.print("A>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("이미 있는 이름입니다. 처음으로 돌아갑니다.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("번호>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else if (seatClassNum == 3) {
					System.out.print("B>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							System.out.println("이미 있는 이름입니다. 처음으로 돌아갑니다.");
							isSame = true;
							break;
						}
					}
					if (!isSame) {
						System.out.print("번호>>");
						seatNum = scanner.nextInt();
						userInfo[seatClassNum - 1][seatNum - 1].setName(reservater);
					}
				} else {
					System.out.println("좌석번호 입력이 올바르지 않습니다.");
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
				System.out.println("<<<조회를 완료하였습니다.>>>");
			} else if (menuNum == 3) {
				System.out.print("좌석 S:1, A:2, B:3>>");
				seatClassNum = scanner.nextInt();
				if (seatClassNum == 1) {
					System.out.print("S>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("없는 이름입니다.");
				} else if (seatClassNum == 2) {
					System.out.print("A>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("없는 이름입니다.");
				} else if (seatClassNum == 3) {
					System.out.print("B>> ");
					for (int i = 0; i < 10; i++) {
						System.out.print(userInfo[seatClassNum - 1][i].getName());
					}
					System.out.println();
					System.out.print("이름>>");
					reservater = scanner.next();
					for (int i = 0; i < 10; i++) {
						if (userInfo[seatClassNum - 1][i].getName().equals(reservater)) {
							userInfo[seatClassNum - 1][i].setName("--- ");
							isSame = true;
						}
					}
					if (!isSame)
						System.out.println("없는 이름입니다.");
				} else
					System.out.println("좌석번호 입력이 올바르지 않습니다.");
			} else if (menuNum == 4) {
				break;
			} else {
				System.out.println("메뉴 입력 번호가 잘못되었습니다.");
			}
		}
		scanner.close();
	}
}