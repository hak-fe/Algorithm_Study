import java.util.Scanner;

public class Ch3_16 {

	public static void main(String[] args) {
		// TODO 자동 생성된 메소드 스텁
		Scanner s = new Scanner(System.in);
		System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
		while (true) {
			System.out.print("가위 바위 보!>>");
			String myChoice = s.next(); // 사용자가 선택한 것
			int n = (int) (Math.random() * 3);
			String str[] = { "가위", "바위", "보" };

			if (myChoice.compareTo("그만") == 0) { // 사용자가 그만이라고 입력한 경우
				System.out.println("게임을 종료합니다 . . . .");
				break;
			}
			if (str[n].equals("가위")) { // 컴퓨터가 낸 것이 가위인 경우
				if (myChoice.equals("가위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 비겼습니다.");

				else if (myChoice.equals("바위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 이겼습니다.");

				else if (myChoice.equals("보"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 졌습니다.");

			} else if (str[n].equals("바위")) { // 컴퓨터가 낸 것이 바위인 경우
				if (myChoice.equals("가위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 졌습니다.");

				else if (myChoice.equals("바위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 비겼습니다.");

				else if (myChoice.equals("보"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 이겼습니다.");
			} else if (str[n].equals("보")) { // 컴퓨터가 낸 것이 보인 경우
				if (myChoice.equals("가위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 이겼습니다.");

				else if (myChoice.equals("바위"))
					System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 사용자가 졌습니다.");
			} else if (myChoice.equals("보"))
				System.out.println("사용자 = " + myChoice + " , 컴퓨터 = " + str[n] + ", 비겼습니다.");
		}
	}
}
