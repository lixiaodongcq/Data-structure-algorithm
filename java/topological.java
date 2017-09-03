
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Scanner;

public class topological {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Node> res = new ArrayList<>();
        HashMap<String, Node> relation = new HashMap<>();
        boolean flag = true;
        while (sc.hasNext()) {
            String str = sc.nextLine();
            parse(str, relation);
            if (str.charAt(str.length() - 1) != ',')
                break;
        }
        while (!relation.isEmpty() && flag == true) {
            flag = false;
            Node node = null;
            for (Map.Entry<String, Node> entry : relation.entrySet()) {
                Node cur = entry.getValue();
                if (cur.degree == 0) {
                    node = cur;
                    break;
                }
            }
            if (node != null) {
                for (Node temp : node.relation) {
                    temp.degree--;
                }
                res.add(node);
                relation.remove(node.name);
                flag = true;
            }
        }
        for (Map.Entry<String, Node> entry : relation.entrySet()) {
            res.add(entry.getValue());
        }
        Collections.sort(res, new Comparator<Node>() {
            public int compare(Node a, Node b) {
                return a.name.compareTo(b.name);
            }
        });
        for (int i = 0; i < res.size() - 1; i++) {
            boolean b = res.get(i).degree == 0 ? false : true;
            System.out.println("{" + res.get(i).name + ", " + b + "},");
        }
        boolean b = res.get(res.size() - 1).degree == 0 ? false : true;
        System.out.println("{" + res.get(res.size() - 1).name + ", " + b + "}");
    }
    public static void parse(String str, HashMap<String, Node> relation) {
        String[] strs = str.split(",");
        String A = strs[0].substring(1, strs[0].length());
        String B = strs[1].substring(1, strs[1].length() - 1);
        Node nodeA = relation.get(A);
        if (nodeA == null) {
            nodeA = new Node(A, null, 1);
            relation.put(A, nodeA);
        } else {
            nodeA.degree++;
        }
        Node nodeB = relation.get(B);
        if (nodeB == null) {
            nodeB = new Node(B, nodeA, 0);
            relation.put(B, nodeB);
        } else {
            nodeB.relation.add(nodeA);
        }
    }

    public static class Node {
        public String name; // 节点的名称
        public LinkedList<Node> relation = new LinkedList<>(); // 节点的依赖，即那些节点可以指向此节点
        public int degree; // 节点的度

        public Node (String name, Node relation, int degree) {
            this.name = name;
            if (relation != null)this.relation.add(relation);
            this.degree = degree;
        }
    }
}
