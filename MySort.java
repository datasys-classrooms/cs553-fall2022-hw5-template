import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

class MySort
{
    public static final String USE = "jar mysort.jar <input file> <output file> <number of threads>";

    private String inputFile;
    private String outputFile;
    private int numThreads;

    public MySort(String inputFile, String outputFile, int numThreads)
    {
        this.inputFile = inputFile;
        this.outputFile = outputFile;
        this.numThreads = numThreads;
    }

    public void sort()
    {
        byte[] buffer = new byte[100];
        InputStream inputStream;
        OutputStream outputStream;

        try {
            inputStream = new FileInputStream(inputFile);
            outputStream = new FileOutputStream(outputFile);
            
            while (inputStream.read(buffer) == 100) {
                outputStream.write(buffer);
            }

            inputStream.close();
            outputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[])
    {
        if (args.length != 3) {
            System.err.println(USE);
            System.exit(1);
        }

        String inputFile = new String(args[0]);
        String outputFile = new String(args[1]);
        int numThreads = Integer.parseInt(args[2]);
        MySort mysort = new MySort(inputFile, outputFile, numThreads);

        long start, end;
        double execTime;

        start = System.nanoTime();
        mysort.sort();
        end = System.nanoTime();
        execTime = Double.valueOf(end - start).doubleValue() / 1000000000.0;

        System.out.println("input file: " + inputFile);
        System.out.println("output file: " + outputFile);
        System.out.println("number of threads: " + numThreads);
        System.out.println("execution time: " + execTime + " seconds");

        System.exit(0);
    }
}