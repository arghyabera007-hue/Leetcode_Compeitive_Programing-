class Solution {
    public int maxProfit(int[] prices) {
        int buyprice = prices[0];
        int profite = 0 ;

        for(int i = 1 ; i < prices.length ; i++){
            if(buyprice > prices[i]){
                buyprice = prices[i];
            }
            profite = Math.max(profite ,prices[i] - buyprice);
        }
        return profite ;
    }
}