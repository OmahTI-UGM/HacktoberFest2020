 <!DOCTYPE html>
 <html>

 <head>
     <title>Simple Calculator In PHP | Webdevtrick.com</title>
     <meta charset="utf-8">
     <meta http-equiv="X-UA-Compatible" content="IE=edge">
     <meta name="viewport" content="width=device-width, initial-scale=1">
 </head>

 <body>

     <div class="container" style="margin-top: 50px">

         <!-- Calculator form by webdevtrick.com -->
         <form method="post" action="<?php $_PHP_SELF ?>">
             <input name="no1" type="text" />
             <select name="operation">
                 <option value="tambah">+</option>
                 <option value="kurang">-</option>
                 <option value="kali">X</option>
                 <option value="bagi">/</option>
             </select>
             <input name="no2" type="text" />
             <input name="submit" type="submit" value="hitung" />
         </form>
         <?php
			
				if(isset($_POST['submit']))
				{
					if(is_numeric($_POST['no1']) && is_numeric($_POST['no2']))
					{
						// Calculate total
						if($_POST['operation'] == 'tambah')
						{
							$total = $_POST['no1'] + $_POST['no2'];	
						    $tanda = "+";
                        }
						if($_POST['operation'] == 'kurang')
						{
							$total = $_POST['no1'] - $_POST['no2'];
                            $tanda = "-";
						}
						if($_POST['operation'] == 'kali')
						{
							$total = $_POST['no1'] * $_POST['no2'];
                            $tanda = "X";
						}
						if($_POST['operation'] == 'bagi')
						{
							$total = $_POST['no1'] / $_POST['no2'];
                            $tanda = "/";
						}
						echo "<h1>Hasilnya</h1>";
						echo "<h2>{$_POST['no1']} {$tanda} {$_POST['no2']} = {$total}</h2>";
					
					} else {
						
						echo 'Masukin Angga Boi';
					
					}
				}
			?>
     </div>

 </body>

 </html>
