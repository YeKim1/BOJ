import java.util.*;
import java.io.*;


class Main {
    public static int N, M, V;

    public static List<List<Integer>> list;
    public static boolean[] visit;

    public static void dfs(int cur) {
        System.out.print(cur + " ");
        visit[cur] = true;

        for (int next : list.get(cur)) {
            if (!visit[next]) dfs(next);
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        list = new ArrayList<>(N+1);
        visit = new boolean[N+1];

        for (int i = 0; i <= N; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            list.get(n1).add(n2);
            list.get(n2).add(n1);
        }

        for(List<Integer> l : list) {
           Collections.sort(l);
        }

        dfs(V);
        System.out.println();

        Arrays.fill(visit, false);

        Queue<Integer> que = new LinkedList<>();
        que.offer(V);
        visit[V] = true;

        while(!que.isEmpty()) {
            int cur = que.poll();
            System.out.print(cur + " ");

            for (int next : list.get(cur)) {
                if (next!=0 && !visit[next]) {
                    que.offer(next);
                    visit[next] = true;
                }
            }
        }

    }
}