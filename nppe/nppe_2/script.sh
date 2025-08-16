
total_price=0
while read -r line; do 
    if [[ "$line" == *"<li>Item"* ]]; then
        price=$(echo "$line" | grep -o 'item-price">Rs\. [0-9]\+' | grep -o '[0-9]\+')
        quantity=$(echo $line | grep -0 'item-qty">[0-9]\+' | grep -o '[0-9]\+')
        total_bill=$((total_bill + price*quantity))
    fi
done
echo $total_bill