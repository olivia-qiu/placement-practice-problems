/* Solution to paths problem.  Version w/ integer assignment ids
 */

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.io.*;

public class CoopTest extends Test {
    /**
     * runTest: run the test in the specified file.  Returns true, if the test passes
     *   and false otherwise.
     **/
    public boolean runTest(File f, boolean verbose) {
        List<Ingredient> family_ingredients = null;
        List<Ingredient> recipe_ingredients = null;
        List<Order> orders = null;

        try {
            Scanner scanner = new Scanner(f);
            String[] line0 = scanner.nextLine().split(" ");            
            int num_family_lines = Integer.parseInt(line0[0]);
            int num_recipe_lines = Integer.parseInt(line0[1]);        
            int num_orders = Integer.parseInt(line0[2]);
            
            family_ingredients = loadIngredients(scanner, num_family_lines);
            recipe_ingredients = loadIngredients(scanner, num_recipe_lines);
            orders = loadOrders(scanner, num_orders);
        } catch (FileNotFoundException e) {
            if (verbose) {
                System.out.println("Results file not found:" + f.getPath());
            }
            return false;
        } catch (NumberFormatException e) {
            if (verbose) {
                System.out.println("Format error: line 0");
            }
            return false;
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Unexpected exception: " + e);
            }
            return false;
        }

        // run the student's code
        Map<String, Integer> actual = null;
        try {
            actual = Coop.mkCoopOrder(family_ingredients, recipe_ingredients, orders);
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Unexpected exception when running student code: " + e);
            }
            return false;
        }

        return checkResult(f, actual, verbose);
    }

    /**
     * loadIngredients: load list of lines of the form: name ingredient amount
     **/
    private static List<Ingredient> loadIngredients(Scanner scanner, int num_to_load) {
        List<Ingredient> ingredients = new ArrayList<Ingredient>();

        for (int i = 0; i < num_to_load; i++) {
            String[] line = scanner.nextLine().split(" ");
            String name = line[0];
            String ingredient = line[1];
            int amount = Integer.parseInt(line[2]);

            ingredients.add(new Ingredient(ingredient, name, amount));
        }

        return ingredients;
    }

    /**
     * loadOrders: load list of lines of the form: family_name recipe_name
     **/
    private static List<Order> loadOrders(Scanner scanner, int num_to_load) {
        List<Order> orders = new ArrayList<Order>();

        for (int i = 0; i < num_to_load; i++) {
            String[] line = scanner.nextLine().split(" ");
            orders.add(new Order(line[0], line[1]));
        }

        return orders;
    }


    /**
     * checkResults: check the actual value against the expected
     * results in the file.
     **/
    private boolean checkResult(File inputFile, Map<String, Integer> actual, boolean verbose) {
        Scanner scanner = TestHelpers.getResultsFileScanner(inputFile);

        if (scanner == null) {
            return false;
        }

        int num = 0;
        try {
            while (scanner.hasNextLine()) {
                String[] data = scanner.nextLine().split(" ");
                String ingredient = data[0];
                int amount = Integer.parseInt(data[1]);
                num++;

                boolean found = false;
                if (actual.containsKey(ingredient)) {
                    if (actual.get(ingredient) != amount) {
                        return false;
                    }
                }
            }
        } catch (NumberFormatException e) {
            if (verbose) {
                System.out.println("Format error: line 0");
            }
            return false;
        } catch (Exception e) {
            if (verbose) {
                System.out.println("Unexpected exception: " + e);
            }
            return false;
        }

        // check for extra keys in actual
        return (actual.size() == num);

    }
    
    public static void main(String[] args) {
        System.exit(TestHelpers.doTests(args, new CoopTest()));
    }
    

}

