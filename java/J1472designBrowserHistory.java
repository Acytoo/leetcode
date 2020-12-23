import java.util.*;

public class J1472designBrowserHistory {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class BrowserHistory {

  private Deque<String> histories;
  private Deque<String> futures;
  private String cur;

  public BrowserHistory(String homepage) {
    histories = new ArrayDeque<>();
    futures = new ArrayDeque<>();
    cur = homepage;
  }

  public void visit(String url) {
    futures = new ArrayDeque<>();
    histories.addLast(cur);
    cur = url;
  }

  public String back(int steps) {

    while (histories.size() > 0 && steps > 0) {
      futures.addLast(cur);
      cur = histories.getLast();
      histories.removeLast();
      --steps;
    }
    return cur;
  }

  public String forward(int steps) {

    while (futures.size() > 0 && steps > 0) {
      histories.addLast(cur);
      cur = futures.getLast();
      futures.removeLast();
      --steps;
    }
    return cur;
  }
}
